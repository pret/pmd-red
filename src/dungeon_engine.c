#include "global.h"
#include "globaldata.h"
#include "dungeon_engine.h"
#include "run_dungeon.h"
#include "dungeon_vram.h"
#include "dungeon_main.h"
#include "constants/dungeon.h"
#include "dungeon_ai_leader.h"
#include "dungeon_ai.h"
#include "dungeon_range.h"
#include "dungeon_misc.h"
#include "dungeon_util.h"
#include "dungeon_leveling.h"
#include "dungeon_turn_effects.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "constants/ability.h"
#include "dungeon_logic.h"
#include "dungeon_cutscene.h"
#include "menu_input.h"
#include "weather.h"

extern void sub_807E378(void);
extern u8 DisplayActions(u32);
extern void sub_805F02C(void);
extern void sub_8071B48(void);

static void sub_8044454(void);
static bool8 RunLeaderTurn(bool8);
static void sub_8044574(void);
static void sub_8044820(void);
static void TrySpawnMonsterAndActivatePlusMinus(void);
static void sub_8044AB4(void);

EWRAM_DATA DungeonPos gLeaderPosition = {0};
EWRAM_DATA MenuInputStruct gDungeonMenu = {0};

const s16 gSpeedTurns[NUM_SPEED_COUNTERS][25] = {
    [0] = {0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 2, 0, 0, 0, 0, 0, 0, 0, 3, 0},
    [1] = {0, 0, 0, 4, 0, 0, 0, 5, 0, 0, 0, 6, 0, 0, 0, 7, 0, 0, 0, 8, 0, 0, 0, 9, 0},
    [2] = {0, 10, 0, 11, 0, 12, 0, 13, 0, 14, 0, 15, 0, 16, 0, 17, 0, 18, 0, 19, 0, 20, 0, 21, 0},
    [3] = {0, 22, 23, 24, 0, 25, 26, 27, 0, 28, 29, 30, 0, 31, 32, 33, 0, 34, 35, 36, 0, 37, 38, 39, 0},
    [4] = {40, 41, 42, 43, 44, 45, 46, 47, 48, 49, 50, 51, 52, 53, 54, 55, 56, 57, 58, 59, 60, 61, 62, 63, 64},
};

void RunFractionalTurn(bool8 param_1)
{
    bool8 cVar2;

    if (IsFloorOver()) return;
    TrySpawnMonsterAndActivatePlusMinus();
    if (IsFloorOver()) return;
    cVar2 = RunLeaderTurn(param_1);
    if (IsFloorOver()) return;
    if (cVar2) {
        sub_807E378();
        if (IsFloorOver()) return;
    }
    if (IsFloorOver()) return;
    sub_8044574();
    if (IsFloorOver()) return;
    sub_8044820();
    if (IsFloorOver()) return;
    sub_8044AB4();
    if (++gDungeon->unk644.fractionalTurn == 24) {
        gDungeon->unk644.fractionalTurn = 0;
    }
}

static bool8 RunLeaderTurn(bool8 param_1)
{
    EntityInfo *entityInfo;
    s32 movSpeed;
    Entity *entity = GetLeader();
    if (entity == NULL)
        return FALSE;

    TryActivateArtificialWeatherAbilities();
    movSpeed = CalcSpeedStage(entity);
    if (gSpeedTurns[movSpeed][gDungeon->unk644.fractionalTurn] == 0)
        return FALSE;
    if (GetEntInfo(entity)->attacking)
        return FALSE;

    while (1) {
        entity = GetLeader();
        if (entity == NULL)
            return FALSE;
        if (DisplayActions(0) == 0 && (gDungeon->unk644.unk28 != 0 || (gDungeon->unk644.unk2F != 0))) {
            DungeonRunFrameActions(0xc);
        }
        GetEntInfo(entity)->speedStageChanged = FALSE;
        if (IsFloorOver())
            return FALSE;
        gDungeon->unkB8 = entity;
        gDungeon->unkBC = 0;
        if (param_1) {
            param_1 = FALSE;
        }
        else {
            TickStatusAndHealthRegen(entity);
        }

        if (IsFloorOver())
            return FALSE;
        EnemyEvolution(entity);
        gDungeon->noActionInProgress = TRUE;
        DungeonHandlePlayerInput();
        gDungeon->noActionInProgress = FALSE;
        if (IsFloorOver())
            break;
        sub_8072CF4(entity);
        sub_8086AC0();
        TryForcedLoss(0);
        if (IsFloorOver())
            break;
        entityInfo = GetEntInfo(entity);
        if (entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY) {
            GetEntInfo(entity)->flags = (entityInfo->flags & ~(MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) | MOVEMENT_FLAG_UNK_14;
        }
        if (IsFloorOver())
            break;
        sub_8044454();
        if (IsFloorOver())
            break;

        if (gDungeon->unkBC != 0) {
            sub_805F02C();
            gDungeon->unkBC = 0;
            param_1 = TRUE;
        }
        else {
            if (!GetEntInfo(entity)->speedStageChanged)
                break;
            gDungeon->unk644.fractionalTurn = 0;
        }
    }

    return TRUE;
}

static void sub_8044454(void)
{
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  if (gDungeon->unkE) {
    gDungeon->unkE = 0;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->activePokemon[index];
      if ((EntityIsValid(entity)) && (entityInfo = GetEntInfo(entity), (entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY))) {
        if (IsFloorOver()) break;
        TickStatusAndHealthRegen(entity);
        if (EntityIsValid(entity)) {
          EnemyEvolution(entity);
          RunMonsterAI(entity, 0);
          sub_8072CF4(entity);
          sub_8086AC0();
          TryForcedLoss(0);
          entityInfo->flags = (entityInfo->flags & ~(MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)) | MOVEMENT_FLAG_UNK_14;
        }
      }
    }
  }
}

void sub_80444F4(Entity *pokemon)
{
  Entity *entity;
  EntityInfo *entityInfo;
  s32 index;

  if (pokemon == GetLeader() && gDungeon->unkE) {
    gDungeon->unkE = 0;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
      entity = gDungeon->activePokemon[index];
      if ((EntityIsValid(entity)) && (pokemon != entity) && (entityInfo = GetEntInfo(entity), (entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY))) {
        if (IsFloorOver()) break;
        RunMonsterAI(entity, 0);
        sub_8072CF4(entity);
        sub_8086AC0();
        TryForcedLoss(0);
      }
    }
  }
}

struct Struct_8044574
{
    Entity *entityPtr;
    struct Struct_8044574 *next;
};

static void sub_8044574(void)
{
    s32 i, id;
    struct Struct_8044574 sp0[4];
    struct Struct_8044574 sp40[4];

    Entity *leader = GetLeader();
    for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
        Entity *teamMon = gDungeon->teamPokemon[i];
        if (EntityIsValid(teamMon)) {
            EntityInfo *teamMonInfo = GetEntInfo(teamMon);
            if (!teamMonInfo->isTeamLeader) {
                s32 spdStage;

                if (IsFloorOver())
                    break;
                gDungeon->unkB8 = teamMon;
                TryActivateArtificialWeatherAbilities();
                teamMonInfo->aiAllySkip = FALSE;

                spdStage = CalcSpeedStage(teamMon);
                if (gSpeedTurns[spdStage][gDungeon->unk644.fractionalTurn] != 0
                    && !teamMonInfo->attacking
                    && !(teamMonInfo->flags & 0x8000))
                {
                    if (teamMonInfo->flags & 0x4000) {
                        teamMonInfo->flags &= ~(0x4000);
                    }
                    else {
                        teamMonInfo->recalculateFollow = FALSE;
                        TickStatusAndHealthRegen(teamMon);
                        if (EntityIsValid(teamMon)) {
                            s32 j;

                            EnemyEvolution(teamMon);
                            for (j = 0; j < 3; j++) {
                                RunMonsterAI(teamMon, 0);
                                if (IsFloorOver() || !sub_8072CF4(teamMon))
                                    break;
                                sub_8086AC0();
                                TryForcedLoss(0);
                                if (IsFloorOver())
                                    break;
                            }
                        }
                    }
                }
            }
        }
    }

    for (id = 0; id < 3; id++) {
        struct Struct_8044574 *ptr;

        for (i = 0; i < 3; i++) {
            sp0[i].entityPtr = NULL;
            sp0[i].next = &sp0[i+1];
        }
        sp0[3].entityPtr = NULL;
        sp0[3].next = NULL;

        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityIsValid(teamMon)) {
                EntityInfo *teamMonInfo = GetEntInfo(teamMon);
                if (teamMonInfo->aiAllySkip) {
                    if (teamMonInfo->isTeamLeader) {
                        teamMonInfo->recalculateFollow = FALSE;
                        teamMonInfo->aiAllySkip = FALSE;
                    }
                    else {
                        s32 x = abs(leader->pos.x - teamMon->pos.x);
                        s32 y = abs(leader->pos.y - teamMon->pos.y);
                        s32 distance = max(x, y);

                        if (distance >= 3)
                            distance = 2;

                        sp40[i].entityPtr = teamMon;
                        sp40[i].next = sp0[distance].next;
                        sp0[distance].next = &sp40[i];
                    }
                }
            }
        }

        ptr = &sp0[0];
        while (ptr != NULL) {
            Entity *entity = ptr->entityPtr;
            if (entity != NULL) {
                EntityInfo *info = GetEntInfo(entity);
                info->recalculateFollow = TRUE;
                info->aiAllySkip = FALSE;
                RunMonsterAI(entity,1);
                sub_8072CF4(entity);
                sub_8086AC0();
                TryForcedLoss(0);
                EntityIsValid(entity); // Does nothing
            }
            ptr = ptr->next;
        }
    }

    if (!IsFloorOver()) {
        for (i = 0; i < MAX_TEAM_MEMBERS; i++) {
            Entity *teamMon = gDungeon->teamPokemon[i];
            if (EntityIsValid(teamMon)) {
                EntityInfo *teamMonInfo = GetEntInfo(teamMon);
                if (teamMonInfo->aiAllySkip) {
                    ApplyEndOfTurnEffects(teamMon);
                    if (EntityIsValid(teamMon)) {
                        EnemyEvolution(teamMon);
                        teamMonInfo->aiAllySkip = FALSE;
                    }
                }
            }
        }
    }
}

static void sub_8044820(void)
{
  s32 movSpeed;
  EntityInfo *entityInfo;
  EntityInfo *entityInfo2;
  Entity * entity;
  Entity * entity2;
  s32 index;

  for (index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++) {
    entity = gDungeon->wildPokemon[index];
    if (EntityIsValid(entity)) {
      if (IsFloorOver()) break;
      entityInfo = GetEntInfo(entity);
      gDungeon->unkB8 = entity;
      TryActivateArtificialWeatherAbilities();
      if ((entityInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY) == 0) {
        if ((u16)(entityInfo->flags & MOVEMENT_FLAG_UNK_14) != 0) {
            entityInfo->flags &= ~(MOVEMENT_FLAG_UNK_14);
        }
        else
        {
          entityInfo->aiAllySkip = FALSE;
          movSpeed = CalcSpeedStage(entity);
          if (gSpeedTurns[movSpeed][gDungeon->unk644.fractionalTurn] != 0) {
            if (!entityInfo->attacking) {
              entityInfo->flags &= ~(MOVEMENT_FLAG_UNK_14 | MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY);
              entityInfo->recalculateFollow = FALSE;
              TickStatusAndHealthRegen(entity);
              if (EntityIsValid(entity)) {
                EnemyEvolution(entity);
                RunMonsterAI(entity, 0);
                if (IsFloorOver()) break;
                sub_8072CF4(entity);
                sub_8086AC0();
                TryForcedLoss(0);
                if (IsFloorOver()) break;
              }
            }
          }
        }
      }
    }
  }
  if (IsFloorOver() == 0) {
    for(index = 0; index < DUNGEON_MAX_WILD_POKEMON; index++)
    {
      entity2 = gDungeon->wildPokemon[index];
      if ((EntityIsValid(entity2)) && (entityInfo2 = GetEntInfo(entity2), entityInfo2->aiAllySkip))
      {
        ApplyEndOfTurnEffects(entity2);
        if (EntityIsValid(entity2)) {
          EnemyEvolution(entity2);
          entityInfo2->aiAllySkip = FALSE;
        }
      }
    }
  }
}

static void TrySpawnMonsterAndActivatePlusMinus(void)
{
  EntityInfo * entityInfo;
  Entity *entity;
  u32 isNotEnemy;
  s32 index;

  if (gSpeedTurns[1][gDungeon->unk644.fractionalTurn] != 0) {
    sub_8071B48();
    gDungeon->plusIsActive[0] = FALSE;
    gDungeon->plusIsActive[1] = FALSE;
    gDungeon->minusIsActive[0] = FALSE;
    gDungeon->minusIsActive[1] = FALSE;
    gDungeon->lightningRodPokemon = NULL;
    gDungeon->unk17B38 = 2;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->activePokemon[index];
        if (EntityIsValid(entity)) {
            entityInfo = GetEntInfo(entity);
            entityInfo->attacking = FALSE;

            if(entityInfo->isNotTeamMember)
            {
                isNotEnemy = FALSE;
            }
            else {
                isNotEnemy = TRUE;
            }

            if (AbilityIsActive(entity, ABILITY_LIGHTNINGROD)) {
                gDungeon->lightningRodPokemon = entity;
                gDungeon->unk17B38 = entityInfo->dungeonSpriteId;
            }
            if (AbilityIsActive(entity, ABILITY_MINUS)) {
                gDungeon->minusIsActive[isNotEnemy] = TRUE;
            }
            if (AbilityIsActive(entity, ABILITY_PLUS)) {
                gDungeon->plusIsActive[isNotEnemy] = TRUE;
            }
        }
    }
    TryForcedLoss(0);
  }
}

static void sub_8044AB4(void)
{
  s32 index;

  if (gSpeedTurns[1][gDungeon->unk644.fractionalTurn + 1] != 0) {
    for (index = 0; index < DUNGEON_MAX_POKEMON; index++) {
      if (EntityIsValid(gDungeon->activePokemon[index])) {
        DisplayActions(0);
        break;
      }
    }
    sub_807EAA0(1,0);
    sub_8086AC0();
    TryForcedLoss(0);
  }
}

bool8 IsFloorOver(void)
{
    if (gDungeon->unk4 == 0) {
        if (GetLeader() == NULL) {
            gDungeon->unk644.unk10 = 1;
        }
        else if (gDungeon->unk2 == 1) {
            gDungeon->unk644.unk10 = 2;
        }
        else if (gDungeon->unk2 != 2) {
            return FALSE;
        }
        else {
            gDungeon->unk644.unk10 = 2;
        }
    }
    return TRUE;
}

bool8 sub_8044B84(void)
{
    if(gDungeon->unk10 != 0)
    {
        return TRUE;
    }
    else {
        return IsFloorOver();
    }
}
