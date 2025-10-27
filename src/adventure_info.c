#include "global.h"
#include "globaldata.h"
#include "adventure_info.h"
#include "pokemon.h"
#include "pokemon_3.h"
#include "friend_area.h"
#include "moves.h"
#include "strings.h"
#include "dungeon_info.h"

static EWRAM_DATA struct unkStruct_203B494 sUnknown_2039778 = {0};

EWRAM_INIT struct unkStruct_203B494 *gUnknown_203B494 = { NULL }; // NDS=20EB98C

void sub_8097670(void)
{
    gUnknown_203B494 = &sUnknown_2039778;
}

struct unkStruct_203B494 *sub_8097680(void)
{
    return &sUnknown_2039778;
}

// arm9.bin::0206968C
void SetDungeonLocationInfo(DungeonLocation *dl)
{
    gUnknown_203B494->dungeonLocation.id = dl->id;
    gUnknown_203B494->dungeonLocation.floor = dl->floor;
}

DungeonLocation *GetDungeonLocationInfo(void)
{
    return &gUnknown_203B494->dungeonLocation;
}

void ResetAdventureInfo(void)
{
    s32 index;

    gUnknown_203B494->achievements = 0;
    gUnknown_203B494->thievingSuccesses = 0;
    gUnknown_203B494->numJoined = 0;
    gUnknown_203B494->adventureMovesLearned = 0;
    gUnknown_203B494->numFloorsExplored = 0;
    gUnknown_203B494->friendRescueSuccesses = 0;
    gUnknown_203B494->numEvolved = 0;

    for (index = 0; index < 14; index++)
        gUnknown_203B494->unk1C[index] = 0;

    for (index = 0; index < ARRAY_COUNT_INT(gUnknown_203B494->learnedMoves); index++)
        gUnknown_203B494->learnedMoves[index] = 0;
}

void SetAdventureAchievement(u8 x)
{
    gUnknown_203B494->achievements |= (1 << x);
}

bool8 GetAdventureAchievement(u8 x)
{
    if (gUnknown_203B494->achievements & (1 << x))
        return TRUE;
    return FALSE;
}

const u8 *GetAdventureLogLine(u8 achievement)
{
    return gAdventureLogText[achievement];
}

void ResetNumAdventures(void)
{
    gUnknown_203B494->numAdventures = 0;
}

void IncrementNumAdventures(void)
{
    gUnknown_203B494->numAdventures++;
    if (gUnknown_203B494->numAdventures > 99999)
        gUnknown_203B494->numAdventures = 99999;
}

s32 GetNumAdventures(void)
{
    return gUnknown_203B494->numAdventures;
}

UNUSED static void SetNumAdventures(s32 numAdventures)
{
    gUnknown_203B494->numAdventures = numAdventures;
}

void IncrementFriendRescueSuccesses(void)
{
    gUnknown_203B494->friendRescueSuccesses++;
    if (gUnknown_203B494->friendRescueSuccesses > 99999)
        gUnknown_203B494->friendRescueSuccesses = 99999;

    SetAdventureAchievement(AA_NUM_FRIEND_RESCUE_SUCCESSES);
}

s32 GetFriendRescueSuccesses(void)
{
    return gUnknown_203B494->friendRescueSuccesses;
}

UNUSED static void SetFriendRescueSuccess(s32 numSuccess)
{
    gUnknown_203B494->friendRescueSuccesses = numSuccess;
}

void IncrementNumEvolved(void)
{
    gUnknown_203B494->numEvolved++;
    if (gUnknown_203B494->numEvolved > 99999)
        gUnknown_203B494->numEvolved = 99999;

    SetAdventureAchievement(AA_NUM_POKEMON_EVOLVED);
}

s32 GetAdventureNumEvolved(void)
{
    return gUnknown_203B494->numEvolved;
}

UNUSED static void SetAdventureNumEvolved(s32 numEvolved)
{
    gUnknown_203B494->numEvolved = numEvolved;
}

void IncrementThievingSuccesses(void)
{
    if (gUnknown_203B494->thievingSuccesses < 9999)
        gUnknown_203B494->thievingSuccesses++;

    SetAdventureAchievement(AA_NUM_THIEVING_SUCCESSES);
}

s16 GetThievingSuccesses(void)
{
    return gUnknown_203B494->thievingSuccesses;
}

void IncrementAdventureNumJoined(void)
{
    if (gUnknown_203B494->numJoined < 9999)
        gUnknown_203B494->numJoined++;

    SetAdventureAchievement(AA_NUM_POKEMON_JOINED);
}

s16 GetAdventureNumJoined(void)
{
    return gUnknown_203B494->numJoined;
}

s16 GetAdventureMovesLearned(void)
{
    return gUnknown_203B494->adventureMovesLearned;
}

void IncrementAdventureFloorsExplored(void)
{
    if (gUnknown_203B494->numFloorsExplored < 99999)
        gUnknown_203B494->numFloorsExplored++;

    SetAdventureAchievement(AA_NUM_FLOORS_EXPLORED);
}

s16 GetAdventureFloorsExplored(void)
{
    return gUnknown_203B494->numFloorsExplored;
}

void sub_80978C8(s16 pokeIndex)
{
    s32 baseSpecies = GetBaseSpeciesNoUnown(pokeIndex);
    gUnknown_203B494->unk54[baseSpecies / 32] |=  1 << (baseSpecies % 32);
}

bool8 sub_8097900(s16 pokeIndex)
{
    s32 baseSpecies = GetBaseSpeciesNoUnown(pokeIndex);

    if (gUnknown_203B494->unk1C[baseSpecies / 32] & (1 << (baseSpecies % 32)))
        return TRUE;
    return FALSE;
}

void UpdateAdventureAchievements(void)
{
    bool8 allJoined;
    bool8 allLeaders;
    s32 i, j;
    s32 moveCount;
    Move *move;

    allJoined = TRUE;
    allLeaders = TRUE;

    if (!GetAdventureAchievement(AA_ALL_FRIEND_AREAS) && HasAllFriendAreas())
        SetAdventureAchievement(AA_ALL_FRIEND_AREAS);

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (PokemonExists(&gRecruitedPokemonRef->pokemon[i])) {
            s32 species = gRecruitedPokemonRef->pokemon[i].speciesNum;
            gUnknown_203B494->unk1C[species / 32] |= 1 << species % 32;

            for (j = 0; j < MAX_MON_MOVES; j++) {
                move = &gRecruitedPokemonRef->pokemon[i].moves[j];

                if (MoveFlagExists(move))
                    gUnknown_203B494->learnedMoves[move->id / 32] |= 1 << move->id % 32;
            }
        }
    }

    for (i = 0; i < MONSTER_MAX; i++) {
        if (i == MONSTER_NONE) continue;
        if (i == MONSTER_CASTFORM_SNOWY) continue;
        if (i == MONSTER_CASTFORM_SUNNY) continue;
        if (i == MONSTER_CASTFORM_RAINY) continue;
        if (i == MONSTER_DEOXYS_ATTACK) continue;
        if (i == MONSTER_DEOXYS_DEFENSE) continue;
        if (i == MONSTER_DEOXYS_SPEED) continue;
        if (i == MONSTER_MUNCHLAX) continue;
        if (i == MONSTER_DECOY) continue;
        if (i == MONSTER_STATUE) continue;
        if (i == MONSTER_RAYQUAZA_CUTSCENE) continue;

        if ((gUnknown_203B494->unk54[i / 32] & 1 << i % 32) == 0)
            allLeaders = FALSE;

        if ((gUnknown_203B494->unk1C[i / 32] & 1 << i % 32) != 0) {
            if (i == MONSTER_MOLTRES)
                SetAdventureAchievement(AA_RECRUIT_MOLTRES);

            if (i == MONSTER_ZAPDOS)
                SetAdventureAchievement(AA_RECRUIT_ZAPDOS);

            if (i == MONSTER_ARTICUNO)
                SetAdventureAchievement(AA_RECRUIT_ARTICUNO);

            if (i == MONSTER_DEOXYS_NORMAL)
                SetAdventureAchievement(AA_RECRUIT_DEOXYS);

            if (i == MONSTER_ENTEI)
                SetAdventureAchievement(AA_RECRUIT_ENTEI);

            if (i == MONSTER_RAIKOU)
                SetAdventureAchievement(AA_RECRUIT_RAIKOU);

            if (i == MONSTER_SUICUNE)
                SetAdventureAchievement(AA_RECRUIT_SUICUNE);

            if (i == MONSTER_HO_OH)
                SetAdventureAchievement(AA_RECRUIT_HO_OH);

            if (i == MONSTER_KYOGRE)
                SetAdventureAchievement(AA_RECRUIT_KYOGRE);

            if (i == MONSTER_GROUDON)
                SetAdventureAchievement(AA_RECRUIT_GROUDON);

            if (i == MONSTER_RAYQUAZA)
                SetAdventureAchievement(AA_RECRUIT_RAYQUAZA);

            if (i == MONSTER_LUGIA)
                SetAdventureAchievement(AA_RECRUIT_LUGIA);

            if (i == MONSTER_CELEBI)
                SetAdventureAchievement(AA_RECRUIT_CELEBI);

            if (i == MONSTER_MEW)
                SetAdventureAchievement(AA_RECRUIT_MEW);

            if (i == MONSTER_MEWTWO)
                SetAdventureAchievement(AA_RECRUIT_MEWTWO);

            if (i == MONSTER_JIRACHI)
                SetAdventureAchievement(AA_RECRUIT_JIRACHI);
        }
        else
            allJoined = FALSE;
    }

    if (allJoined)
        SetAdventureAchievement(AA_ALL_POKEMON_JOINED);

    if (allLeaders)
        SetAdventureAchievement(AA_ALL_POKEMON_LEADERS);

    moveCount = 0;
    for (i = 0; i < NUM_REGULAR_MOVE_IDS; i++) {
        if (i == MOVE_NOTHING || i == MOVE_REGULAR_ATTACK || i == MOVE_IS_WATCHING || i == MOVE_BIDE_2)
            continue;

        if (gUnknown_203B494->learnedMoves[i / 32] & 1 << i % 32)
            moveCount++;
    }

    if (moveCount != 0) {
        gUnknown_203B494->adventureMovesLearned = moveCount;
        SetAdventureAchievement(AA_NUM_MOVES_LEARNED);
    }
}

void WriteAdventureBits(DataSerializer *r0)
{
    UpdateAdventureAchievements();
    WriteBits(r0, &gUnknown_203B494->numAdventures, 17);
    WriteBits(r0, &gUnknown_203B494->friendRescueSuccesses, 17);
    WriteBits(r0, &gUnknown_203B494->numEvolved, 17);
    WriteBits(r0, &gUnknown_203B494->achievements, 32);
    WriteBits(r0, &gUnknown_203B494->thievingSuccesses, 14);
    WriteBits(r0, &gUnknown_203B494->numJoined, 14);
    WriteBits(r0, &gUnknown_203B494->adventureMovesLearned, 9);
    WriteBits(r0, &gUnknown_203B494->numFloorsExplored, 17);
    WriteBits(r0, gUnknown_203B494->unk1C, 14 * 32);
    WriteBits(r0, gUnknown_203B494->unk54, 14 * 32);
    WriteBits(r0, gUnknown_203B494->learnedMoves, ARRAY_COUNT_INT(gUnknown_203B494->learnedMoves) * 32);
    WriteDungeonLocationBits(r0, &gUnknown_203B494->dungeonLocation);
}

void ReadAdventureBits(DataSerializer *r0)
{
    ReadBits(r0, &gUnknown_203B494->numAdventures, 17);
    ReadBits(r0, &gUnknown_203B494->friendRescueSuccesses, 17);
    ReadBits(r0, &gUnknown_203B494->numEvolved, 17);
    ReadBits(r0, &gUnknown_203B494->achievements, 32);
    ReadBits(r0, &gUnknown_203B494->thievingSuccesses, 14);
    ReadBits(r0, &gUnknown_203B494->numJoined, 14);
    ReadBits(r0, &gUnknown_203B494->adventureMovesLearned, 9);
    ReadBits(r0, &gUnknown_203B494->numFloorsExplored, 17);
    ReadBits(r0, gUnknown_203B494->unk1C, 14 * 32);
    ReadBits(r0, gUnknown_203B494->unk54, 14 * 32);
    ReadBits(r0, gUnknown_203B494->learnedMoves, ARRAY_COUNT_INT(gUnknown_203B494->learnedMoves) * 32);
    ReadDungeonLocationBits(r0, &gUnknown_203B494->dungeonLocation);
}
