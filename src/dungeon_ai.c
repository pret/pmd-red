#include "global.h"
#include "dungeon_ai.h"
#include "code_803E668.h"
#include "code_803E724.h"
#include "code_8045A00.h"
#include "dungeon_message.h"
#include "code_8077274_1.h"
#include "code_808417C.h"
#include "constants/ability.h"
#include "constants/direction.h"
#include "constants/dungeon_action.h"
#include "constants/iq_skill.h"
#include "constants/item.h"
#include "constants/status.h"
#include "constants/targeting.h"
#include "constants/type.h"
#include "dungeon_action.h"
#include "dungeon_ai_attack.h"
#include "dungeon_ai_items.h"
#include "dungeon_ai_movement.h"
#include "dungeon_ai_targeting.h"
#include "dungeon_capabilities.h"
#include "dungeon_items.h"
#include "dungeon_leader.h"
#include "dungeon_map_access.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_random.h"
#include "dungeon_util_1.h"
#include "dungeon_util.h"
#include "pokemon.h"
#include "status_checks.h"
#include "structs/map.h"
#include "structs/str_dungeon.h"
#include "dungeon_misc.h"

extern char *gPtrCouldntBeUsedMessage;
extern char *gPtrItsaMonsterHouseMessage;

extern u8 sub_8044B28(void);
extern void sub_807AB38(Entity *, u32);
extern void sub_8041888(u32);

void sub_8075900(Entity *pokemon, u8 r1)
{
    if(EntityIsValid(pokemon))
    {
        if(!GetEntInfo(pokemon)->isNotTeamMember)
        {
            if(!sub_8044B28())
            {
                if(!gDungeon->unk644.monsterHouseTriggered)
                {
                    if((GetTileAtEntitySafe(pokemon)->terrainType & TERRAIN_TYPE_IN_MONSTER_HOUSE))
                    {
                        // It's a monster house!
                        LogMessageByIdWithPopupCheckUser(GetLeader(), gPtrItsaMonsterHouseMessage);
                        gDungeon->unk644.monsterHouseTriggeredEvent = TRUE;
                        sub_807AB38(pokemon, r1);
                        sub_8041888(0);
                        if(sub_803F428(&pokemon->pos))
                            sub_803E708(0x78, 0x39);
                    }
                }
            }
        }
    }
}

void RunMonsterAI(Entity *pokemon, u32 unused)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    if (pokemonInfo->flags & MOVEMENT_FLAG_SWAPPING_PLACES_PETRIFIED_ALLY)
    {
        if (pokemonInfo->frozenClassStatus.status == STATUS_PETRIFIED)
        {
            EndFrozenClassStatus(pokemon, pokemon);
        }
    }
    else
    {
        pokemonInfo->decoyAITracker = DECOY_AI_NONE;
        if (pokemonInfo->monsterBehavior == BEHAVIOR_FIXED_ENEMY || ShouldRunMonsterAI(pokemon))
        {
            if (pokemonInfo->monsterBehavior != BEHAVIOR_RESCUE_TARGET && pokemonInfo->useHeldItem)
            {
                if (CheckVariousConditions(pokemon))
                {
                    pokemonInfo->useHeldItem = FALSE;
                    SubstitutePlaceholderStringTags(gFormatBuffer_Monsters[0], pokemon, 0);
                    LogMessageByIdWithPopupCheckUser(pokemon, gPtrCouldntBeUsedMessage);
                    return;
                }
                AIDecideUseItem(pokemon);
                if (pokemonInfo->action.action != ACTION_NOTHING)
                {
                    return;
                }
            }
            if (!HasStatusThatPreventsActing(pokemon))
            {
                if (gDungeon->decoyIsActive)
                {
                    s32 i;
                    Entity *target;
                    for (i = 0; i < DUNGEON_MAX_POKEMON; i++)
                    {
                        target = gDungeon->activePokemon[i];
                        if (EntityIsValid(target) &&
                            GetEntInfo(target)->curseClassStatus.status == STATUS_DECOY &&
                            CanSeeTarget(pokemon, target))
                        {
                            bool8 applierNonTeamMemberFlag = GetEntInfo(target)->curseClassStatus.applierNonTeamMemberFlag;
                            u8 decoyAITracker = DECOY_AI_TEAM;
                            if (applierNonTeamMemberFlag)
                            {
                                decoyAITracker = DECOY_AI_WILD;
                            }
                            pokemonInfo->decoyAITracker = decoyAITracker;
                            break;
                        }
                    }
                }
                ClearMonsterActionFields(&pokemonInfo->action);
                if (pokemonInfo->monsterBehavior == BEHAVIOR_RESCUE_TARGET)
                {
                    SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                    pokemonInfo->action.direction = DungeonRandInt(NUM_DIRECTIONS);
                    pokemonInfo->targetPos.x = pokemon->pos.x;
                    pokemonInfo->targetPos.y = pokemon->pos.y - 1;
                }
                else
                {
                    AIDecideUseItem(pokemon);
                    if (pokemonInfo->action.action == ACTION_NOTHING)
                    {
                        if (!IQSkillIsEnabled(pokemon, IQ_DEDICATED_TRAVELER))
                        {
                            ChooseAIMove(pokemon);
                            if (pokemonInfo->action.action != ACTION_NOTHING)
                            {
                                return;
                            }
                            if (pokemonInfo->cringeClassStatus.status == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (!GetCanMoveFlag(pokemonInfo->id))
                                {
                                    return;
                                }
                                AIMovement(pokemon, TRUE);
                            }
                        }
                        else
                        {
                            if (pokemonInfo->cringeClassStatus.status == STATUS_CONFUSED)
                            {
                                SetActionPassTurnOrWalk(&pokemonInfo->action, pokemonInfo->id);
                            }
                            else
                            {
                                if (GetCanMoveFlag(pokemonInfo->id))
                                {
                                    AIMovement(pokemon, TRUE);
                                }
                                if (pokemonInfo->action.action > ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                ChooseAIMove(pokemon);
                                if (pokemonInfo->action.action <= ACTION_PASS_TURN)
                                {
                                    return;
                                }
                                pokemonInfo->aiTarget.aiNotNextToTarget = FALSE;
                                pokemonInfo->aiAllySkip = FALSE;
                                pokemonInfo->waiting = FALSE;
                            }
                        }
                    }
                }
            }
        }
    }
}
