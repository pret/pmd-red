#include "global.h"
#include "status_checks_1.h"

#include "constants/ability.h"
#include "constants/iq_skill.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "dungeon_engine.h"
#include "dungeon_global_data.h"
#include "dungeon_items.h"
#include "dungeon_movement.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_map_access.h"
#include "dungeon_util.h"
#include "code_800D090.h"
#include "code_80521D0.h"
#include "pokemon.h"
#include "weather.h"

extern void sub_80429B4(Entity *r0);

extern u8 *gUnknown_80FEE80[];
extern u8 *gUnknown_80F8974[];
extern u8 *gUnknown_80F8994[];
extern u8 *gUnknown_80F8968[];
extern u8 *gUnknown_80F8988[];
extern u8 gUnknown_8106FA4[];
void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index);

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
        if (displayMessage && SetVisualFlags(pokemon->info, 0x40, flag)) {
            sub_80429B4(pokemon);
            SendMessage(pokemon, *gUnknown_80FEE80);
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
    if (((gDungeon->blinded ||
        gDungeon->hallucinating) ||
        (param_2->transformStatus == STATUS_INVISIBLE)) &&
        (param_2->isNotTeamMember))
    {
        strcpy(buffer, *gUnknown_80F8988);
    }
    else
    {
        if (param_2->waitingStatus == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8968);
        }
        else
        {
            if (param_2->isNotTeamMember) {
                if ((param_2->joinedAt == 0x4A) || (param_2->clientType == CLIENT_TYPE_CLIENT)) {
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
    if (entityInfo->waitingStatus == STATUS_DECOY) {
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
    if (((gDungeon->blinded ||
          gDungeon->hallucinating) ||
          (entityInfo->transformStatus == STATUS_INVISIBLE)) &&
          (entityInfo->isNotTeamMember))
    {
            strcpy(buffer, *gUnknown_80F8994);
    }
    else
    {
        if (entityInfo->waitingStatus == STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8974);
        }
        else
        {
            if (entityInfo->isNotTeamMember) {
                CopyMonsterNametoBuffer(buffer, entityInfo->apparentID);
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
    EntityInfo *pokemonInfo = pokemon->info;
    s32 i;
    if (pokemonInfo->sleep == STATUS_SLEEP ||
        pokemonInfo->sleep == STATUS_NIGHTMARE ||
        pokemonInfo->sleep == STATUS_YAWNING ||
        pokemonInfo->nonVolatileStatus != STATUS_NONE ||
        (pokemonInfo->immobilizeStatus != STATUS_INGRAIN && pokemonInfo->immobilizeStatus != STATUS_NONE) ||
        pokemonInfo->volatileStatus != STATUS_NONE ||
        pokemonInfo->waitingStatus == STATUS_CURSED ||
        pokemonInfo->waitingStatus == STATUS_DECOY ||
        pokemonInfo->linkedStatus == STATUS_LEECH_SEED ||
        pokemonInfo->moveStatus == STATUS_WHIFFER ||
        pokemonInfo->eyesightStatus == STATUS_BLINKER ||
        pokemonInfo->eyesightStatus == STATUS_CROSS_EYED ||
        pokemonInfo->muzzled == TRUE ||
        pokemonInfo->exposed ||
        pokemonInfo->perishSongTurns != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        Move *moves = pokemonInfo->moves;
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
    if (pokemon->info->sleep != STATUS_SLEEP &&
        pokemon->info->sleep != STATUS_NAPPING &&
        pokemon->info->sleep != STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasLowHealth(Entity *pokemon)
{
    EntityInfo *pokemonInfo = pokemon->info;
    EntityInfo *pokemonInfo2 = pokemon->info;
    s32 maxHPStat = pokemonInfo->maxHPStat;
    if (maxHPStat < 0)
    {
        maxHPStat += 3;
    }
    if (pokemonInfo2->HP <= maxHPStat >> 2)
    {
        return TRUE;
    }
    return FALSE;
}
