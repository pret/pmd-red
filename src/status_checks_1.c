#include "global.h"
#include "status_checks_1.h"

#include "constants/ability.h"
#include "constants/status.h"
#include "constants/weather.h"
#include "dungeon_global_data.h"
#include "dungeon_pokemon_attributes.h"
#include "dungeon_util.h"
#include "code_800D090.h"
#include "code_80521D0.h"
#include "pokemon.h"
#include "weather.h"

extern void sub_80429B4(struct DungeonEntity *r0);

extern u8 *gUnknown_80FEE80[];
extern u8 *gUnknown_80F8974[];
extern u8 *gUnknown_80F8994[];
extern u8 *gUnknown_80F8968[];
extern u8 *gUnknown_80F8988[];
extern u8 gUnknown_8106FA4[];

u8 sub_8070828(struct DungeonEntity *pokemon, bool8 displayMessage)
{
    bool8 flag;

    flag = FALSE;
    if (!EntityExists(pokemon)) {
        return 0;
    }
    else {
        if ((HasAbility(pokemon, ABILITY_SWIFT_SWIM)) && (GetWeather(pokemon) == WEATHER_RAIN)) {
            flag = TRUE;
        }
        if ((HasAbility(pokemon, ABILITY_CHLOROPHYLL)) && (GetWeather(pokemon) == WEATHER_SUNNY)) {
            flag = TRUE;
        }
        if (displayMessage && SetVisualFlags(pokemon->entityData, 0x40, flag)) {
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

void SetMessageArgument_2(u8 *buffer, struct DungeonEntityData *param_2, s32 colorNum)
{
    if (((gDungeonGlobalData->displayBlinker ||
        gDungeonGlobalData->displayCrossEyed) ||
        (param_2->transformStatus == TRANSFORM_STATUS_INVISIBLE)) &&
        (param_2->isEnemy))
    {
        strcpy(buffer, *gUnknown_80F8988);
    }
    else
    {
        if (param_2->waitingStatus == WAITING_STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8968);
        }
        else
        {
            if (param_2->isEnemy) {
                if ((param_2->joinLocation == 0x4A) || (param_2->clientType == CLIENT_TYPE_CLIENT)) {
                    CopyYellowSpeciesNametoBuffer(buffer, param_2->transformSpecies);
                }
                else
                CopyCyanSpeciesNametoBuffer(buffer, param_2->transformSpecies);
            }
            else
            {
                sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[param_2->partyIndex],colorNum);
            }
        }
    }
}

void sub_8070968(u8 *buffer, struct DungeonEntityData *entityData, s32 colorNum)
{
    if (entityData->waitingStatus == WAITING_STATUS_DECOY) {
        sprintf_2(buffer, gUnknown_8106FA4, colorNum + 0x30, *gUnknown_80F8974);
    }
    else if (entityData->isEnemy) {
        CopyCyanSpeciesNametoBuffer(buffer, entityData->transformSpecies);
    }
    else {
        sub_808D9DC(buffer, &gRecruitedPokemonRef->pokemon2[entityData->partyIndex], colorNum);
    }
}

void sub_80709C8(u8 *buffer, struct DungeonEntityData *entityData)
{
    if (((gDungeonGlobalData->displayBlinker ||
          gDungeonGlobalData->displayCrossEyed) ||
          (entityData->transformStatus == TRANSFORM_STATUS_INVISIBLE)) &&
          (entityData->isEnemy))
    {
            strcpy(buffer, *gUnknown_80F8994);
    }
    else
    {
        if (entityData->waitingStatus == WAITING_STATUS_DECOY) {
            strcpy(buffer, *gUnknown_80F8974);
        }
        else
        {
            if (entityData->isEnemy) {
                CopySpeciesNametoBuffer(buffer, entityData->transformSpecies);
            }
            else
            {
                sub_808DA0C(buffer, &gRecruitedPokemonRef->pokemon2[entityData->partyIndex]);
            }
        }
    }
}

bool8 HasNegativeStatus(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    s32 i;
    if (pokemonData->sleepStatus == SLEEP_STATUS_SLEEP ||
        pokemonData->sleepStatus == SLEEP_STATUS_NIGHTMARE ||
        pokemonData->sleepStatus == SLEEP_STATUS_YAWNING ||
        pokemonData->nonVolatileStatus != NON_VOLATILE_STATUS_NONE ||
        (pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_INGRAIN && pokemonData->immobilizeStatus != IMMOBILIZE_STATUS_NONE) ||
        pokemonData->volatileStatus != VOLATILE_STATUS_NONE ||
        pokemonData->waitingStatus == WAITING_STATUS_CURSED ||
        pokemonData->waitingStatus == WAITING_STATUS_DECOY ||
        pokemonData->linkedStatus == LINKED_STATUS_LEECH_SEED ||
        pokemonData->moveStatus == MOVE_STATUS_WHIFFER ||
        pokemonData->eyesightStatus == EYESIGHT_STATUS_BLINKER ||
        pokemonData->eyesightStatus == EYESIGHT_STATUS_CROSS_EYED ||
        pokemonData->muzzledStatus == MUZZLED_STATUS_MUZZLED ||
        pokemonData->exposedStatus ||
        pokemonData->perishSongTimer != 0)
    {
        return TRUE;
    }
    for (i = 0; i < MAX_MON_MOVES; i++)
    {
        struct PokemonMove *moves = pokemonData->moves;
        if (moves[i].moveFlags & MOVE_FLAG_EXISTS && moves[i].moveFlags2 & MOVE_FLAG_SEALED)
        {
            return TRUE;
        }
    }
    for (i = 0; i < NUM_SPEED_TURN_COUNTERS; i++)
    {
        if (pokemonData->slowTurnsLeft[i] != 0)
        {
            return TRUE;
        }
    }
    return FALSE;
}

bool8 IsSleeping(struct DungeonEntity *pokemon)
{
    if (pokemon->entityData->sleepStatus != SLEEP_STATUS_SLEEP &&
        pokemon->entityData->sleepStatus != SLEEP_STATUS_NAPPING &&
        pokemon->entityData->sleepStatus != SLEEP_STATUS_NIGHTMARE)
    {
        return FALSE;
    }
    return TRUE;
}

bool8 HasQuarterHPOrLess(struct DungeonEntity *pokemon)
{
    struct DungeonEntityData *pokemonData = pokemon->entityData;
    struct DungeonEntityData *pokemonData2 = pokemon->entityData;
    s32 maxHP = pokemonData->maxHP;
    if (maxHP < 0)
    {
        maxHP += 3;
    }
    if (pokemonData2->HP <= maxHP >> 2)
    {
        return TRUE;
    }
    return FALSE;
}
