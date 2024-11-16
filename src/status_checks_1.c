#include "global.h"
#include "status_checks_1.h"

#include "code_800D090.h"
#include "dungeon_message.h"
#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_items.h"
#include "dungeon_map_access.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "pokemon_mid.h"
#include "pokemon.h"
#include "structs/str_dungeon.h"
#include "weather.h"

extern void sub_80429B4(Entity *r0);

extern u8 *gUnknown_80FEE80[];
extern u8 *gUnknown_80F8974[];
extern u8 *gUnknown_80F8994[];
extern u8 *gUnknown_80F8968[];
extern u8 *gUnknown_80F8988[];
extern u8 gUnknown_8106FA4[];

s32 sub_8070828(Entity *pokemon, bool8 displayMessage)
{
    bool8 flag;

    flag = FALSE;
    if (!EntityExists(pokemon)) {
        return 0;
    }
    else {
        if ((HasAbility(pokemon, ABILITY_SWIFT_SWIM)) && (GetApparentWeather(pokemon) == WEATHER_RAIN)) {
            flag = TRUE;
        }
        if ((HasAbility(pokemon, ABILITY_CHLOROPHYLL)) && (GetApparentWeather(pokemon) == WEATHER_SUNNY)) {
            flag = TRUE;
        }
        if (displayMessage && SetVisualFlags(GetEntInfo(pokemon), 0x40, flag)) {
            sub_80429B4(pokemon);
            LogMessageByIdWithPopupCheckUser(pokemon, *gUnknown_80FEE80);
        }
        if (flag) {
            return 2;
        }
        else {
            return 1;
        }
    }
}

void SetMessageArgument_2(u8 *buffer, EntityInfo *param_2, s32 colorNum)
{
    if (((gDungeon->unk181e8.blinded ||
        gDungeon->unk181e8.hallucinating) ||
        (param_2->invisibleClassStatus.status == STATUS_INVISIBLE)) &&
        (param_2->isNotTeamMember))
    {
        strcpy(buffer, *gUnknown_80F8988);
    }
    else
    {
        if (param_2->curseClassStatus.status == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8968);
        }
        else
        {
            if (param_2->isNotTeamMember) {
                if ((param_2->joinedAt.joinedAt == 0x4A) || (param_2->monsterBehavior == BEHAVIOR_RESCUE_TARGET)) {
                    CopyYellowMonsterNametoBuffer(buffer, param_2->apparentID);
                }
                else
                CopyCyanMonsterNametoBuffer(buffer, param_2->apparentID);
            }
            else
            {
                sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[param_2->teamIndex],colorNum);
            }
        }
    }
}

void sub_8070968(u8 *buffer, EntityInfo *entityInfo, s32 colorNum)
{
    if (entityInfo->curseClassStatus.status == STATUS_DECOY) {
        sprintfStatic(buffer, gUnknown_8106FA4, colorNum + 0x30, *gUnknown_80F8974);
    }
    else if (entityInfo->isNotTeamMember) {
        CopyCyanMonsterNametoBuffer(buffer, entityInfo->apparentID);
    }
    else {
        sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[entityInfo->teamIndex], colorNum);
    }
}

void sub_80709C8(u8 *buffer, EntityInfo *entityInfo)
{
    if (((gDungeon->unk181e8.blinded ||
          gDungeon->unk181e8.hallucinating) ||
          (entityInfo->invisibleClassStatus.status == STATUS_INVISIBLE)) &&
          (entityInfo->isNotTeamMember))
    {
            strcpy(buffer, *gUnknown_80F8994);
    }
    else
    {
        if (entityInfo->curseClassStatus.status == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8974);
        }
        else
        {
            if (entityInfo->isNotTeamMember) {
                CopyMonsterNameToBuffer(buffer, entityInfo->apparentID);
            }
            else
            {
                sub_808DA0C(buffer, &gRecruitedPokemonRef->pokemon2[entityInfo->teamIndex]);
            }
        }
    }
}

bool8 HasNegativeStatus(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    s32 i;
    if (pokemonInfo->sleepClassStatus.status == STATUS_SLEEP ||
        pokemonInfo->sleepClassStatus.status == STATUS_NIGHTMARE ||
        pokemonInfo->sleepClassStatus.status == STATUS_YAWNING ||
        pokemonInfo->burnClassStatus.status != STATUS_NONE ||
        (pokemonInfo->frozenClassStatus.status != STATUS_INGRAIN && pokemonInfo->frozenClassStatus.status != STATUS_NONE) ||
        pokemonInfo->cringeClassStatus.status != STATUS_NONE ||
        pokemonInfo->curseClassStatus.status == STATUS_CURSED ||
        pokemonInfo->curseClassStatus.status == STATUS_DECOY ||
        pokemonInfo->linked.status == STATUS_LEECH_SEED ||
        pokemonInfo->sureShotClassStatus.status == STATUS_WHIFFER ||
        pokemonInfo->blinkerClassStatus.status == STATUS_BLINKER ||
        pokemonInfo->blinkerClassStatus.status == STATUS_CROSS_EYED ||
        pokemonInfo->muzzled.muzzled == TRUE ||
        pokemonInfo->exposed ||
        pokemonInfo->perishSongTurns != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        Move *moves = pokemonInfo->moves.moves;
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags2 & MOVE_FLAG_SEALED)
        {
            return TRUE;
        }
    }
    for (i = 0; i < NUM_SPEED_COUNTERS; i++)
    {
        if (pokemonInfo->speedDownCounters[i] != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsSleeping(Entity *pokemon)
{
    if (GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_SLEEP &&
        GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_NAPPING &&
        GetEntInfo(pokemon)->sleepClassStatus.status != STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasLowHealth(Entity *pokemon)
{
    EntityInfo *pokemonInfo = GetEntInfo(pokemon);
    s32 maxHPStat = pokemonInfo->maxHPStat;
    if (maxHPStat < 0)
    {
        maxHPStat += 3;
    }
    if (pokemonInfo->HP <= maxHPStat >> 2)
    {
        return TRUE;
    }
    return FALSE;
}
