#include "global.h"
#include "code_803E668.h"
#include "code_8045A00.h"
#include "code_80521D0.h"
#include "code_8077274_1.h"
#include "code_807CD9C.h"
#include "code_808417C.h"
#include "constants/dungeon_action.h"
#include "constants/dungeon.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "dungeon_capabilities.h"
#include "dungeon_items.h"
#include "dungeon_music.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util.h"
#include "move_effects_target.h"
#include "moves.h"
#include "number_util.h"
#include "pokemon.h"
#include "status.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "structs/str_position.h"

extern u8 gAvailablePokemonNames[];
extern u8 gFormatItems[];

extern s16 gTypeGummiIQBoost[NUM_TYPES][NUMBER_OF_GUMMIS];

extern u8 *gUnknown_80F89F4[];
extern u8 *gUnknown_80FB580[];
extern s16 gUnknown_80F4FB6;
extern s16 gUnknown_80F4FB8;
extern s16 gUnknown_80F4FBA;
extern s16 gUnknown_80F4FBC;
extern s16 gUnknown_80F4FBE;
extern s16 gUnknown_80F4F46; // 0xC
extern s16 gUnknown_80F4FA2;
extern s16 gUnknown_80F4FA4; // 0x14
extern s16 gUnknown_80F4FA6; // 0x2D
extern s16 gUnknown_80F4FA8; // 0xF
extern s16 gUnknown_80F4FAA; // 0x1E
extern u32 gUnknown_8106A4C;
extern u32 gUnknown_8106A50;
extern s16 gUnknown_80F4FAC;
extern s16 gUnknown_80F503A;
extern s16 gUnknown_80F503C;
extern s16 gUnknown_80F503E;
extern s16 gUnknown_80F5040;
extern s16 gUnknown_80F5042;
extern s16 gUnknown_80F5044;
extern s16 gUnknown_80F5046;
extern s16 gUnknown_80F5048;
extern s16 gUnknown_80F4FAE;
extern s16 gUnknown_80F4FAC;
extern s16 gUnknown_80F4E74[];

extern u8 *gUnknown_80FDBB8[];
extern u8 *gUnknown_80FE458[];
extern u8 *gItemStickyDoesntWorkText[];
extern u8 *gUnknown_80FEAE8[];
extern u8 *gUnknown_80FDBA0[];
extern u8 *gUnknown_80FE434[];
extern u8 *gUnknown_80FE40C[];
extern u8 *gUnknown_80FE454[];
extern u8 *gPtrSelfHealPreventedHungerMessage[];
extern u8 *gUnknown_80F9740[];
extern u8 *gUnknown_80F9760[];
extern u8 *gUnknown_80FD644[];
extern u8 *gUnknown_80FD648[];
extern u8 *gUnknown_80FD6E8[];
extern u8 *gPtrCantUseInDungeonMessage[];
extern u8 *gItemStickyDoesntWorkText[];
extern u8 *gPtrMusicBoxPlayedCrumbledMessage[];
extern u8 *gPtrWishStoneCrumbledMessage[];
extern u8 *gPtrIcePartCrumbledMessage[];
extern u8 *gPtrRockPartCrumbledMessage[];
extern u8 *gPtrSteelPartCrumbledMessage[];
extern u8 *gUnknown_80FDCA4[];
extern u8 *gItemStickyDoesntWorkText[];
extern u8 *gUnknown_80FECA0[];
extern u8 *gItemStickyDoesntWorkText[];
extern u8 *gUnknown_80F9BD8[];

#include "data/code_8048480.h"

extern void sub_80421C0(Entity *r0, u16 r1);
extern void sub_8078B5C(Entity *, Entity *, u32, u32, u32);
extern u8 sub_806A538(s32);
extern void sub_8051E7C(Entity *pokemon);
extern void sub_8045BF8(u8 *, Item *);
extern void sub_8063B54(ActionContainer *);
extern void sub_80637E8(ActionContainer *);
extern void sub_8063BB4(ActionContainer *);
extern void sub_8063CF0(ActionContainer *, u32);
extern void sub_8063A70(ActionContainer *, u32);
extern u8 sub_8062F90(Entity *, u32, u32, u32, u32);
extern void sub_8044DF0(Entity *, u32, u32);
extern s32 sub_8052B8C(u32, u8 *, u32);
extern void sub_803EAF0(u32, u32);
extern void sub_8044C10(bool8);
Entity *DrawFieldGiveItemMenu(u32, u32);
extern void PrintFieldMessage(u32, u8 *, u32);
extern void sub_8044E24(Entity *, u32, u32);
extern void sub_804245C(Entity *, Item *);
extern u8 sub_8072938(Entity *, u16);
extern void sub_8072008(Entity *pokemon, Entity *r1, u32 r2, u8 r3, u32);
extern void LevelDownTarget(Entity *pokemon, Entity *r1, u32 r2);
extern void sub_80522F4(Entity *pokemon, Entity *r1, const u8[]);
extern void sub_806F370(Entity *pokemon, Entity *r1, u32, u32, u8 *, u8, s32, u32, u32, u32);
extern s32 sub_8042520(Entity *);
Entity *sub_80696FC(Entity *);
extern void sub_806A7E8(EntityInfo *, s32);
extern u32 sub_8055640(struct Entity *, struct Entity *, struct Move *, u32, u32);

void StunSeedItemAction(Entity *, Entity *);
void MaxElixirAction(Entity *, Entity *);
void ProteinItemAction(Entity *, Entity *);
void CalciumItemAction(Entity *, Entity *);
void IronItemAction(Entity *, Entity *);
void ZincItemAction(Entity *, Entity *);
void sub_80487CC(Entity *, Entity *, u32, u32);
void GrimyFoodItemAction(Entity *, Entity *);
void HandleGummiItemAction(Entity *, Entity *, u8);
void IcePartItemAction(Entity *, Entity *, u8);
void SteelPartItemAction(Entity *, Entity *, u8);
void RockPartItemAction(Entity *, Entity *, u8);
void MusicBoxItemAction(Entity *, Entity *, u8);
void nullsub_94(Entity *, Entity *, u8);
void KeyItemAction(Entity *, Entity *, u8);
void sub_8078B5C(Entity *, Entity *, u32, u32, u32);
void sub_8048340(Entity *, Entity *, u32);
void HealSeedItemAction(Entity *, Entity *, u8);
void WishStoneItemAction(Entity *, Entity *, u8);
void OranBerryItemAction(Entity *, Entity *);
void ChestoBerryItemAction(Entity *, Entity *);
void JoySeedItemAction(Entity *, Entity *);
void GinsengItemAction(Entity *, Entity *);
void BlastSeedItemAction(Entity *, Entity *, u8);
void SitrusBerryItemAction(Entity *, Entity *);
void WarpSeedItemAction(Entity *, Entity *);
void PlainSeedItemAction(Entity *, Entity *);
void SleepSeedItemAction(Entity *, Entity *);
void TotterSeedItemAction(Entity *, Entity *);
void CheriBerryItemAction(Entity *, Entity *);
void PechaBerryItemAction(Entity *, Entity *);
void QuickSeedItemAction(Entity *, Entity *);
void HungerSeedItemAction(Entity *, Entity *);
void RawstBerryItemAction(Entity *, Entity *);
void LifeSeedItemAction(Entity *, Entity *);
void AllureSeedItemAction(Entity *, Entity *);
void EyedropSeedItemAction(Entity *, Entity *);
void BlinkerSeedItemAction(Entity *, Entity *);
void DoomSeedItemAction(Entity *, Entity *);
void sub_80482FC(Entity *, Entity *, u32, u8);

extern void sub_8071DA4(Entity *);
extern void SetShopkeeperAggression(Entity *, Entity *);
extern void sub_80464C8(Entity *, Position *, Item *);
extern void sub_806A6E8(Entity *);
extern void sub_8042390(Entity *, Item *);

bool8 sub_8047930(Entity *pokemon, Entity *target)
{
  bool8 flag;

  if (((target->info->shopkeeper == TRUE) ||
      (target->info->clientType == 4)) || (target->info->clientType == CLIENT_TYPE_CLIENT)) {
    return FALSE;
  }
  else {
    if(DungeonRandInt(100) < gUnknown_80F4FA2)
        flag = TRUE;
    else
        flag = FALSE;
    if (GetEntityType(pokemon) == ENTITY_MONSTER) {
      if (HasHeldItem(pokemon, ITEM_WHIFF_SPECS)) {
          flag = FALSE;
      }
      else {
        if (HasHeldItem(pokemon, ITEM_LOCKON_SPECS)) {
          flag = TRUE;
        }
      }
    }
    if ((GetEntityType(target) == ENTITY_MONSTER) && (HasHeldItem(target, ITEM_DODGE_SCARF))) {
      flag = FALSE;
    }
  }
  return flag;
}

void sub_80479B8(char param_1, char param_2, u8 param_3, Entity *pokemon, Entity *target, Item *item)
{
  EntityInfo *info;
  u32 flag;
  u8 uStack_24;
  u8 uStack_23;
  u8 auStack_22;

  if (param_1 != '\0') {
    if (param_2 == '\0') {
      flag = FALSE;
      info = target->info;
      if (info->isNotTeamMember) {
        if ((GetItemCategory(item->id) != CATEGORY_THROWN_LINE) && (GetItemCategory(item->id) != CATEGORY_BERRIES_SEEDS_VITAMINS)) {
          flag = GetItemCategory(item->id) == CATEGORY_THROWN_ARC ? FALSE : TRUE;
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
      if (flag && ((info->heldItem.flags & ITEM_FLAG_EXISTS) == 0)) {
        if (info->shopkeeper == TRUE) {
          sub_80464C8(pokemon,&target->pos,item);
          return;
        }
        PlaySoundEffect(0x14d);
        sub_8045BF8(gFormatItems,item);
        SetMessageArgument(gAvailablePokemonNames,target,0);
        sub_80522F4(pokemon,target,*gUnknown_80FDBB8); // $m0 caught the $i0
        info->heldItem = *item;
        sub_806A6E8(target);
        return;
      }
    }
    if (param_1 != '\0') {
      sub_8042390(target,item);
      SetShopkeeperAggression(pokemon,target);
    }
  }
  if ((item->flags & ITEM_FLAG_STICKY)) {
    sub_8045BF8(gFormatItems,item);
    sub_80522F4(pokemon,target,*gItemStickyDoesntWorkText);
    if (param_1 != '\0') {
      sub_806F370(pokemon,target,gUnknown_80F4FAE,1,&uStack_24,0,0x217,0,0,0);
      sub_8071DA4(pokemon);
      return;
    }
    else goto _jump;
  }
  else {
    if (param_1 == 0)
_jump:
        sub_804245C(target,item);
  }
  if (GetItemCategory(item->id) == CATEGORY_BERRIES_SEEDS_VITAMINS) {
    sub_8078B5C(pokemon,target,5,0,0);
  }
  if ((GetItemCategory(item->id) == CATEGORY_TMS_HMS) || (GetItemCategory(item->id) == CATEGORY_LINK_BOX)) {
    if (param_1 != '\0') {
        sub_806F370(pokemon,target,gUnknown_80F4FAC,1,&uStack_23,0,0x217,0,0,0);
        goto _080482B4;
    }
    else
    {
        sub_80522F4(pokemon,target,*gUnknown_80FE458);
        goto _080482B4;
    }
  }
  switch(item->id) {
      case ITEM_STICK:
        sub_80482FC(pokemon,target,gUnknown_80F503A,1);
        break;
      case ITEM_IRON_THORN:
        sub_80482FC(pokemon,target,gUnknown_80F503C,2);
        break;
      case ITEM_SILVER_SPIKE:
        sub_80482FC(pokemon,target,gUnknown_80F503E,3);
        break;
      case ITEM_GOLD_FANG:
        sub_80482FC(pokemon,target,gUnknown_80F5040,4);
        break;
      case ITEM_CACNEA_SPIKE:
        sub_80482FC(pokemon,target,gUnknown_80F5042,5);
        break;
      case ITEM_CORSOLA_TWIG:
        sub_80482FC(pokemon,target,gUnknown_80F5044,6);
        break;
      case ITEM_GEO_PEBBLE:
        sub_8048340(pokemon,target,gUnknown_80F5048);
        break;
      case ITEM_GRAVELEROCK:
        sub_8048340(pokemon,target,gUnknown_80F5046);
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
      case 0xe9:
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
        if (param_1 != '\0') {
            sub_806F370(pokemon,target,gUnknown_80F4FAC,1,&auStack_22,0,0x217,0,0,0);
        }
        else
        {
            sub_80522F4(pokemon,target,*gUnknown_80FE458);
        }
        break;
  }
_080482B4:
  sub_8071DA4(pokemon);
}

UNUSED void nullsub_205(void) { }

void SleepSeedItemAction(Entity *pokemon, Entity *target)
{
    sub_8075C58(pokemon, target, CalculateStatusTurns(target, gUnknown_80F4E74, TRUE), TRUE);
}

void sub_80482FC(Entity *pokemon, Entity *target, u32 pp, u8 param_4)
{
    Move move;

    InitPokemonMove(&move, MOVE_PROJECTILE);
    move.PP = pp;
    sub_8055640(pokemon, target, &move, 0x100, param_4);
}

void sub_8048340(Entity *pokemon, Entity *target, u32 r2)
{
    sub_806F370(pokemon, target, r2, 1, 0, 0, 528, 0, 0, 0);
}

void HealSeedItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    sub_8079F20(pokemon, target, 1, r2);
}

void OranBerryItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FB6, gUnknown_80F4FB8, TRUE);
}

void SitrusBerryItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, gUnknown_80F4FBA, gUnknown_80F4FBC, TRUE);
}

void MaxElixirAction(Entity *pokemon, Entity *target)
{
    RestorePPTarget(pokemon, target, 999);
}

void LifeSeedItemAction(Entity *pokemon, Entity *target)
{
    HealTargetHP(pokemon, target, 0, gUnknown_80F4FBE, TRUE);
}

void BlinkerSeedItemAction(Entity *pokemon, Entity *target)
{
    BlindTarget(pokemon, target);
}

void AllureSeedItemAction(Entity *pokemon, Entity *target)
{
    CrossEyeVisionTarget(pokemon, target);
}

void QuickSeedItemAction(Entity *pokemon, Entity *target)
{
    RaiseMovementSpeedTarget(pokemon, target, 0, TRUE);
}

void EyedropSeedItemAction(Entity *pokemon, Entity *target)
{
    RestoreVisionTarget(pokemon, target);
}

void CheriBerryItemAction(Entity *pokemon, Entity *target)
{
    if(target->info->nonVolatile.nonVolatileStatus == STATUS_PARALYSIS)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void PechaBerryItemAction(Entity *pokemon, Entity *target)
{
    if((u8)(target->info->nonVolatile.nonVolatileStatus - 2) <= 1)
        SendNonVolatileEndMessage(pokemon, target);
    else
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void WarpSeedItemAction(Entity *pokemon, Entity *target)
{
    sub_807D148(pokemon, target, 0, NULL);
}

void ChestoBerryItemAction(Entity *pokemon, Entity *target)
{
    SleeplessStatusTarget(pokemon, target);
}

void TotterSeedItemAction(Entity *pokemon, Entity *target)
{
    ConfuseStatusTarget(pokemon, target, TRUE);
}

void JoySeedItemAction(Entity *pokemon, Entity *target)
{
    sub_8072008(pokemon, target, 1, 1, 1);
}

void StunSeedItemAction(Entity *pokemon, Entity *target)
{
    PetrifiedStatusTarget(pokemon, target);
}

void PlainSeedItemAction(Entity *pokemon, Entity *target)
{
    // Pointer to "But nothing happened!"
    sub_80522F4(pokemon, target, *gUnknown_80F89F4);
}

void DoomSeedItemAction(Entity *pokemon, Entity *target)
{
    LevelDownTarget(pokemon, target, 1);
}

void RawstBerryItemAction(Entity *pokemon, Entity *target)
{
    if(target->info->nonVolatile.nonVolatileStatus == STATUS_BURN)
        SendNonVolatileEndMessage(pokemon, target);
    else
    {
        SetMessageArgument(gAvailablePokemonNames, target, 0);
        // Pointer to "But nothing happened!"
        sub_80522F4(pokemon, target, *gUnknown_80FB580);
    }
}

void HungerSeedItemAction(Entity *pokemon, Entity * target)
{
  EntityInfo *entityInfo = target->info;
  if (target->info->isTeamLeader)
    sub_8078A58(pokemon, target, 0, 5);
  else
  {
    entityInfo = target->info;
    SetMessageArgument(gAvailablePokemonNames, target, 0);
    if (IQSkillIsEnabled(target, IQ_SELF_CURER))
        sub_80522F4(pokemon, target, *gPtrSelfHealPreventedHungerMessage);
    else
    {
      if (FixedPointToInt(entityInfo->belly) != 0) {
        entityInfo->belly = IntToFixedPoint(0);
        sub_80522F4(pokemon, target, *gUnknown_80F9740);
      }
      else
        sub_80522F4(pokemon, target, *gUnknown_80F9760);
    }
  }
}

void GinsengItemAction(Entity *pokemon, Entity * target)
{
  bool8 isMoveBoosted;
  s32 moveIndex;
  EntityInfo *entityInfo;
#ifndef NONMATCHING
  register Move *movePtr1 asm("r4"); // r4
  register Move *movePtr2 asm("r5"); // r5
#else
  Move *movePtr1; // r4
  Move *movePtr2; // r5
#endif
  u8 moveBoost;
  s32 movePowerBoost;
  s32 maxPowerBoost;

  isMoveBoosted = FALSE;
  moveBoost = 1;
  entityInfo = target->info;
  if (DungeonRandInt(100) < gUnknown_80F4F46)
    moveBoost = 3;
  if (entityInfo->isTeamLeader) {
    for(moveIndex = 0, movePtr1 = &entityInfo->moves[0], movePtr2 = movePtr1; moveIndex < MAX_MON_MOVES; movePtr1++, movePtr2++, moveIndex++)
    {
        if((movePtr1->moveFlags & MOVE_FLAG_EXISTS) && (movePtr1->moveFlags & MOVE_FLAG_SET))
        {
            if(GetMoveBasePower(movePtr2) == 0) continue;
            movePowerBoost = movePtr1->ginseng;
            maxPowerBoost = GetMoveMaxUpgradeLevel(movePtr2);
            movePtr1->ginseng += moveBoost;
            if(movePtr1->ginseng >= maxPowerBoost)
                movePtr1->ginseng = maxPowerBoost;
            if(movePowerBoost != movePtr1->ginseng)
                isMoveBoosted = TRUE;
        }
    }

    if (isMoveBoosted) {
      sub_80522F4(pokemon,target,*gUnknown_80FE454);
      if (moveBoost != 1) {
        sub_803E708(10,0x40);
        sub_80522F4(pokemon,target,*gUnknown_80FE434);
     }
    }
    else
      sub_80522F4(pokemon,target,*gUnknown_80FE40C);
  }
  else
     sub_80522F4(pokemon,target,*gUnknown_80FE40C);
}

void BlastSeedItemAction(Entity *pokemon, Entity * target, u8 param_3)
{
  s32 uVar1;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo_1;
  Entity *entity;
  u8 auStack28 [4];

  if (param_3 != 0) {
    entityInfo = target->info;
    entityInfo_1 = entityInfo;
    if (gDungeon->unk675 != 0) {
        uVar1 = gUnknown_80F4FA8;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
    }
    else {
        uVar1 = gUnknown_80F4FA4;
    }
    if (entityInfo_1->immobilize.immobilizeStatus == STATUS_FROZEN) {
      SendImmobilizeEndMessage(pokemon, target);
    }
    sub_806F370(pokemon, target, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
  }
  else
  {
    sub_8042520(pokemon);
    entity = sub_80696FC(pokemon);
    if (entity == NULL)
    {
      sub_80522F4(pokemon, target, *gUnknown_80FDBA0);
    }
    else
    {
      entityInfo = entity->info;
      if (gDungeon->unk675 != 0) {
        uVar1 = gUnknown_80F4FAA;
        sub_80522F4(pokemon, target, *gUnknown_80FEAE8);
      }
      else {
        uVar1 = gUnknown_80F4FA6;
      }
      if (entityInfo->immobilize.immobilizeStatus == STATUS_FROZEN) {
        SendImmobilizeEndMessage(pokemon, entity);
      }
      sub_806F370(pokemon, entity, uVar1, 1, auStack28, 0, 0x216, 0, 0, 0);
    }
  }
}

void sub_80487CC(Entity *pokemon, Entity * target, u32 param_3, u32 param_4)
{
    sub_8078B5C(pokemon, target, param_3, param_4, 1);
}

void HandleGummiItemAction(Entity *pokemon, Entity *target, u8 gummiIndex)
{
  s32 iVar3;
  EntityInfo *targetInfo;
  s32 gummiBoost;
  s32 baseIQ;
  s32 iVar4;
  s32 iVar5;
  s32 currIQ;

  targetInfo = target->info;
  gummiBoost = gTypeGummiIQBoost[targetInfo->types[0]][gummiIndex];
  gummiBoost += gTypeGummiIQBoost[targetInfo->types[1]][gummiIndex];
  sub_8078B5C(pokemon,target,
             gUnknown_810A808[targetInfo->types[0]][gummiIndex] +
             gUnknown_810A808[targetInfo->types[1]][gummiIndex],0,1);
  if (!targetInfo->isNotTeamMember) {
    if (!IsClientOrTeamBase(targetInfo->joinedAt.joinedAt)) {
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
        sub_80522F4(pokemon,target,*gUnknown_80FD644);
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
        sub_80522F4(pokemon,target,gUnknown_80FD648[iVar4]);
        sub_80522F4(pokemon,target,gUnknown_80FD6E8[iVar3]);
        LoadIQSkills(target);
        sub_806A7E8(targetInfo,baseIQ);
      }
    }
  }
}

void ProteinItemAction(Entity *pokemon, Entity *target)
{
    RaiseAtkStatTarget(pokemon, target, 3);
}

void CalciumItemAction(Entity *pokemon, Entity *target)
{
    RaiseSpAtkStatTarget(pokemon, target, 3);
}

void IronItemAction(Entity *pokemon, Entity *target)
{
    RaiseDefStatTarget(pokemon, target, 3);
}

void ZincItemAction(Entity *pokemon, Entity *target)
{
    RaiseSpDefStatTarget(pokemon, target, 3);
}

void nullsub_94(Entity *pokemon, Entity *target, u8 r2)
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
        PrintFieldMessage(0,*gItemStickyDoesntWorkText,1);
        return FALSE;
    }
    else if (IsHMItem(item->id)) {
        PrintFieldMessage(0,*gPtrCantUseInDungeonMessage,1);
        return FALSE;
    }
    else
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            entity = gDungeon->teamPokemon[index];
            if (EntityExists(entity)) {
                entityInfo = entity->info;
                flag = CanMonLearnMove(moveID, entityInfo->id);
                if (CheckVariousStatuses2(entity, FALSE)) {
                    flag = FALSE;
                }
                if (entityInfo->clientType == CLIENT_TYPE_CLIENT) {
                    flag = FALSE;
                }
                if (IsClientOrTeamBase(entityInfo->joinedAt.joinedAt)) {
                    flag = FALSE;
                }
                entityInfo->unk157 = flag;
            }
        }
        entity2 = DrawFieldGiveItemMenu(0,1);
        if (!EntityExists(entity2)) {
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
  PokemonStruct2 *pokemon;

  if ((item->flags & ITEM_FLAG_STICKY)) {
    PrintFieldMessage(0,*gItemStickyDoesntWorkText,1);
    return FALSE;
  }
  else
  {
    if (gDungeon->unk65C == 0) {
        PrintFieldMessage(0,*gUnknown_80F9BD8,1);
        return FALSE;
    }
    else
    {
      for(index = 0; index < MAX_TEAM_MEMBERS; index++)
      {
        entity = gDungeon->teamPokemon[index];
        if (EntityExists(entity)) {
          pEVar6 = entity->info;
          flag = TRUE;
          if(((MAX_TEAM_MEMBERS - 1) < pEVar6->teamIndex))
             flag =  FALSE;
          else
          {
             pokemon = &gRecruitedPokemonRef->pokemon2[pEVar6->teamIndex];
             if (sub_806A538(pokemon->unkA))
                 flag =  FALSE;
          }

          if (CheckVariousStatuses2(entity, FALSE)) {
            flag = FALSE;
          }
          if (pEVar6->clientType == CLIENT_TYPE_CLIENT) {
            flag = FALSE;
          }
          if (IsClientOrTeamBase(pEVar6->joinedAt.joinedAt)) {
            flag = FALSE;
          }
          if (pEVar6->isTeamLeader) {
            flag = FALSE;
          }
          pEVar6->unk157 = flag;
        }
      }
      entity2 = DrawFieldGiveItemMenu(0,1);
      if (!EntityExists(entity2)) {
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

// TODO: should be bool8
bool32 sub_8048B9C(Entity *entity,Item *param_2)
{
#ifndef NONMATCHING
  register bool32 bVar2 asm("r8");
#else
  bool32 bVar2;
#endif
  bool8 flag;
  EntityInfo *entityInfo;
  Entity * entity2;
  int index;
  Entity *entity1;
  EntityInfo *entity1Info;
  ActionContainer *actionPointer;
  ActionContainer actionContainer;
  u16 action;

  bVar2 = FALSE;
  entityInfo = entity->info;
  actionPointer = &(entityInfo->action);
  if ((param_2->flags & ITEM_FLAG_STICKY)) {
      PrintFieldMessage(0,*gItemStickyDoesntWorkText,1);
      return FALSE;
  }
  else
  {
    for(index = 0; index < MAX_TEAM_MEMBERS; index++)
    {
      entity1 = gDungeon->teamPokemon[index];
      if (EntityExists(entity1)) {
        entity1Info = entity1->info;
        flag = TRUE;
        if(CheckVariousStatuses2(entity1, FALSE))
        {
            flag = FALSE;
        }
        if(entity1Info->clientType == CLIENT_TYPE_CLIENT)
        {
            flag = FALSE;
        }
        if(IsClientOrTeamBase(entity1Info->joinedAt.joinedAt))
        {
            flag = FALSE;
        }
        entity1Info->unk157 = flag;
      }
    }
    entity2 = DrawFieldGiveItemMenu(0,1);
    if (!EntityExists(entity2)) {
        return FALSE;
    }
    else
    {
      while( TRUE ) {
        entityInfo = entity2->info;
        actionContainer = *actionPointer;
        goto _clear;
_load:
        action = actionPointer->action;
        if (action == ACTION_UNK1D) {
          sub_80637E8(actionPointer);
        }
        else if (action == ACTION_UNK20) {
          sub_803EAF0(0,0);
          sub_8063BB4(actionPointer);
          sub_8044C10(TRUE);
          bVar2 = TRUE;
        }
        else if (action == ACTION_UNK21) {
          sub_803EAF0(0,0);
          sub_8063CF0(actionPointer,0);
          sub_8044C10(TRUE);
        }
        else if ((action == ACTION_SET_MOVE) || (action == ACTION_UNSET_MOVE)) {
          sub_803EAF0(0,0);
          sub_8063A70(actionPointer,0);
        }
        else if (action == ACTION_UNK1F) {
          sub_803EAF0(0,0);
          sub_8063B54(actionPointer);
        }
_clear:
        ClearMonsterActionFields(actionPointer);
        if (sub_8062F90(entity2,1,0,0,1) != 0) {
          if (bVar2)
          {
              if (sub_8052B8C(0,*gUnknown_80FECA0,1) == 1) {
                *actionPointer = actionContainer;
                sub_8044DF0(entity,0,0x6e);
                SetMonsterActionFields(actionPointer,0x2c);
                break;
              }
          }
          else
          {
               sub_8044C10(TRUE);
               break;
          }
        }
        goto _load;
      }
    }
  }
  return bVar2;
}

bool8 sub_8048D50(Entity * pokemon, Item *item)
{
  EntityInfo *entityInfo;

  entityInfo = pokemon->info;

  if ((item->flags & ITEM_FLAG_STICKY) != 0) {
    sub_8045BF8(gFormatItems, item);
    SendMessage(pokemon,*gItemStickyDoesntWorkText);
    return FALSE;
  }
  else
  {
    if ((entityInfo->muzzled.muzzled == TRUE) && (IsEdibleItem(item->id))) {
        SetMessageArgument(gAvailablePokemonNames,pokemon,0);
        SendMessage(pokemon,*gUnknown_80FDCA4);
        return FALSE;
    }
  }
  return TRUE;
}

void KeyItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    u8 temp;
    if(r2 != 0)
        sub_806F370(pokemon, target, gUnknown_80F4FAC, 1, &temp, 0, 0x217, 0, 0, 0);
    else
        sub_8051E7C(pokemon);
}

void GrimyFoodItemAction(Entity *pokemon, Entity * target)
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

void IcePartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    SendMessage(pokemon, *gPtrIcePartCrumbledMessage);
}

void RockPartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    SendMessage(pokemon, *gPtrRockPartCrumbledMessage);
}

void SteelPartItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    SendMessage(pokemon, *gPtrSteelPartCrumbledMessage);
}

void WishStoneItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    SendMessage(pokemon, *gPtrWishStoneCrumbledMessage);
}

void MusicBoxItemAction(Entity *pokemon, Entity *target, u8 r2)
{
    sub_80421C0(pokemon, 0xD6);
    SendMessage(pokemon, *gPtrMusicBoxPlayedCrumbledMessage);
    sub_803E708(0x3C, 0x46);
}
