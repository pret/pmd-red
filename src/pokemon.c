#include "global.h"
#include "globaldata.h"
#include "pokemon.h"
#include "constants/colors.h"
#include "constants/monster.h"
#include "constants/tactic.h"
#include "code_800D090.h"
#include "code_8097DD0.h"
#include "cpu.h"
#include "decompress_at.h"
#include "def_filearchives.h"
#include "exclusive_pokemon.h"
#include "file_system.h"
#include "friend_area.h"
#include "moves.h"
#include "pokemon_3.h"
#include "sprite.h"
#include "text_util.h"
#include "dungeon_data.h"
#include "strings.h"

static EWRAM_DATA MonsterDataEntry *sMonsterParameters = {NULL}; // B=02135090
static EWRAM_DATA OpenedFile *sMonsterParametersFile = {NULL};
static EWRAM_DATA SpriteOAM sShadowSprites[3] = {0};
static EWRAM_DATA RecruitedMon sRecruitedPokemon = {0}; // B=02135560
static EWRAM_DATA s16 sLevelCurrentPokeId = {0};
UNUSED static EWRAM_DATA u16 unused_data[3] = {0};
static EWRAM_DATA LevelData sLevelCurrentData[0x64] = {0}; // TODO: Add MAX_LEVEL define

EWRAM_INIT RecruitedMon *gRecruitedPokemonRef = {NULL}; // B=020EAF94

struct unkStruct_8107654
{
    s16 species;
    s32 unk4;
};

// arm9.bin::0205C34C
void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &sRecruitedPokemon;
    sMonsterParametersFile = OpenFileAndGetFileDataPtr("monspara", &gSystemFileArchive);
    sMonsterParameters = (MonsterDataEntry *)sMonsterParametersFile->data;
    sLevelCurrentPokeId = 0;
    // More in blue
}

// arm9.bin::0205C340
RecruitedMon *GetRecruitedPokemon(void)
{
    return &sRecruitedPokemon;
}

// arm9.bin::0205C2A4
void InitializeRecruitedPokemon(void)
{
    s32 index;

    for (index = 0; index < NUM_MONSTERS; index++)
        gRecruitedPokemonRef->pokemon[index].flags = 0;

    for (index = 0; index < 4; index++)
        gRecruitedPokemonRef->dungeonTeam[index].flags = 0;

    for (index = 0; index < MAX_TEAM_MEMBERS; index++) {
        gRecruitedPokemonRef->team[index].speciesNum = 0;
        gRecruitedPokemonRef->team[index].flags = 0;
    }
}

void sub_808CE74(s16 _species, bool32 _isLeader, u8* name)
{
     struct Pokemon pokemon;
     u8 name_buffer[20];
     u32 friendArea;
     s32 i;
     s32 species = _species;
     bool8 isLeader = _isLeader;

     pokemon.flags = POKEMON_FLAG_EXISTS | POKEMON_FLAG_ON_TEAM;
     if (isLeader) {
         pokemon.isTeamLeader = TRUE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_LEADER;
     }
     else {
         pokemon.isTeamLeader = FALSE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_PARTNER;
     }
     pokemon.level = 1;
     pokemon.pokeHP = GetBaseHP(species);
     pokemon.offense.att[0] = GetBaseOffensiveStat(species, 0);
     pokemon.offense.att[1] = GetBaseOffensiveStat(species, 1);
     pokemon.offense.def[0] = GetBaseDefensiveStat(species, 0);
     pokemon.offense.def[1] = GetBaseDefensiveStat(species, 1);
     pokemon.IQ = 1;
     pokemon.unkC[0].level = 0;
     pokemon.unkC[1].level = 0;
     SetDefaultIQSkills(&pokemon.IQSkills, FALSE);
     pokemon.speciesNum = species;
     pokemon.heldItem.id = ITEM_NOTHING;
     pokemon.heldItem.quantity = 0;
     pokemon.currExp = 0;
     pokemon.tacticIndex = TACTIC_LETS_GO_TOGETHER;
     pokemon.dungeonLocation.floor = 0;
     sub_808E490(pokemon.moves, species);

     if (name == NULL) {
         CopyMonsterNameToBuffer(name_buffer, species);
         BoundedCopyStringtoBuffer(pokemon.name, name_buffer, POKEMON_NAME_LENGTH);
     }
     else {
         s32 j;
         for (j = 0; j < POKEMON_NAME_LENGTH; j++) {
             pokemon.name[j] = name[j];
         }
     }
     friendArea = sMonsterParameters[species].friendArea;
     for (i = 0; i < NUM_MONSTERS; i++) {
         if (!PokemonExists(&gRecruitedPokemonRef->pokemon[i])) {
             u8 speciesFriendArea = sub_80923D4(i);
             if (speciesFriendArea == friendArea) {
                 gRecruitedPokemonRef->pokemon[i] = pokemon;
                 gFriendAreas[speciesFriendArea] = TRUE;
                 sub_80980B4(species);
                 break;
             }
         }
     }
}

void CreateLevel1Pokemon(Pokemon *pokemon, s16 _species, u8* name, u32 _itemID, const DungeonLocation *location, u16 *moves)
{
    u8 name_buffer[20];
    s32 i;

    s32 species = _species;
    u8 itemID = _itemID;

    pokemon->flags = POKEMON_FLAG_EXISTS;
    pokemon->isTeamLeader = FALSE;
    pokemon->level = 1;
    pokemon->pokeHP = GetBaseHP(species);
    pokemon->offense.att[0] = GetBaseOffensiveStat(species, 0);
    pokemon->offense.att[1] = GetBaseOffensiveStat(species, 1);
    pokemon->offense.def[0] = GetBaseDefensiveStat(species, 0);
    pokemon->offense.def[1] = GetBaseDefensiveStat(species, 1);
    pokemon->speciesNum = species;
    InitBulkItem(&pokemon->heldItem, itemID);
    pokemon->currExp = 0;
    pokemon->tacticIndex = TACTIC_LETS_GO_TOGETHER;
    pokemon->IQ = 1;
    pokemon->dungeonLocation = *location;
    pokemon->unkC[0].level = 0;
    pokemon->unkC[1].level = 0;
    SetDefaultIQSkills(&pokemon->IQSkills, FALSE);

    if (moves != NULL) {
        for (i = 0; i < MAX_MON_MOVES; i++) {
            if (moves[i] != 0) {
                InitZeroedPPPokemonMove(&pokemon->moves[i], moves[i]);
            }
            else {
                ResetMoveFlags(&pokemon->moves[i]);
            }
        }
    }
    else {
        sub_808E490(pokemon->moves, species);
    }

    if (name == NULL) {
        CopyMonsterNameToBuffer(name_buffer, species);
        BoundedCopyStringtoBuffer(pokemon->name, name_buffer, POKEMON_NAME_LENGTH);
    }
    else {
        s32 j;
        for (j = 0; j < POKEMON_NAME_LENGTH; j++) {
            pokemon->name[j] = name[j];
        }
    }
}

void sub_808D0D8(Pokemon *pokemon)
{
     pokemon->level = 1;
     pokemon->pokeHP = GetBaseHP(pokemon->speciesNum);
     pokemon->offense.att[0] = GetBaseOffensiveStat(pokemon->speciesNum, 0);
     pokemon->offense.att[1] = GetBaseOffensiveStat(pokemon->speciesNum, 1);
     pokemon->offense.def[0] = GetBaseDefensiveStat(pokemon->speciesNum, 0);
     pokemon->offense.def[1] = GetBaseDefensiveStat(pokemon->speciesNum, 1);
     pokemon->currExp = 0;
     pokemon->tacticIndex = TACTIC_LETS_GO_TOGETHER;
     pokemon->IQ = 1;
     SetDefaultIQSkills(&pokemon->IQSkills, FALSE);
     sub_808E490(pokemon->moves, pokemon->speciesNum);
}

void ConvertStoryMonToPokemon(Pokemon *dst, const struct StoryMonData *src)
{
    s32 i;

    dst->flags = POKEMON_FLAG_EXISTS;
    dst->isTeamLeader = FALSE;
    dst->level = src->level;
    dst->pokeHP = src->pokeHP;
    dst->offense.att[0] = src->offenseAtk[0];
    dst->offense.att[1] = src->offenseAtk[1];
    dst->offense.def[0] = src->offenseDef[0];
    dst->offense.def[1] = src->offenseDef[1];
    dst->speciesNum = src->speciesNum;
    InitBulkItem(&dst->heldItem, src->itemID);
    dst->currExp = src->currExp;
    dst->tacticIndex = TACTIC_LETS_GO_TOGETHER;
    dst->IQ = src->IQ;
    dst->dungeonLocation = src->dungeonLocation;
    dst->unkC[0].level = 0;
    dst->unkC[1].level = 0;
    SetDefaultIQSkills(&dst->IQSkills, FALSE);

    for (i = 0; i < MAX_MON_MOVES; i++) {
        if (src->moveID[i] != 0) {
            InitZeroedPPPokemonMove(&dst->moves[i], src->moveID[i]);
        }
        else {
            dst->moves[i].moveFlags = 0;
        }
    }

    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        dst->name[i] = src->name[i];
    }
}

Pokemon *TryAddPokemonToRecruited(Pokemon *pokemon)
{
    s32 i;
    s32 species = pokemon->speciesNum;
    u32 friendArea = sMonsterParameters[species].friendArea;

    if (!gFriendAreas[friendArea])
        return NULL;
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (!PokemonExists(&gRecruitedPokemonRef->pokemon[i])) {
            u8 speciesFriendArea = sub_80923D4(i);
            if (speciesFriendArea == friendArea) {
                gRecruitedPokemonRef->pokemon[i] = *pokemon;
                gRecruitedPokemonRef->pokemon[i].flags &= ~(POKEMON_FLAG_x4000);
                sub_80980B4(pokemon->speciesNum);
                return &gRecruitedPokemonRef->pokemon[i];
            }
        }
    }
    return NULL;
}

Pokemon *sub_808D278(s32 species)
{
    s32 i;
    s16 species_s16 = (s16)species;
    u32 friendArea = sMonsterParameters[species_s16].friendArea;

    if (!gFriendAreas[friendArea])
        return NULL;

    for (i = 0; i < NUM_MONSTERS; i++) {
        if (!PokemonExists(&gRecruitedPokemonRef->pokemon[i])) {
            u8 speciesFriendArea = sub_80923D4(i);
            if (speciesFriendArea == friendArea) {
                return &gRecruitedPokemonRef->pokemon[i];
            }
        }
    }
    return NULL;
}

Pokemon *TryAddLevel1PokemonToRecruited(s32 species, u8 *name, u32 _itemID, const DungeonLocation *location, u16 *moveID)
{
    Pokemon pokemon;

    CreateLevel1Pokemon(&pokemon, species, name, (u8)_itemID, location, moveID);
    return TryAddPokemonToRecruited(&pokemon);
}

void sub_808D31C(Pokemon *param_1)
{
  if ((!IsMonTeamLeader(param_1)) && !IsMonPartner(param_1))
      param_1->flags = 0;
}

Pokemon * GetPlayerPokemonStruct(void)
{
    s32 index;

    for(index = 0; index < NUM_MONSTERS; index++)
    {
        if(((PokemonExists(&gRecruitedPokemonRef->pokemon[index])))){
            if(IsMonTeamLeader(&gRecruitedPokemonRef->pokemon[index])) {
                return &gRecruitedPokemonRef->pokemon[index];
            }
        }
    }
    return NULL;
}

Pokemon * sub_808D378(void)
{
    s32 index;

    for(index = 0; index < NUM_MONSTERS; index++)
    {
        if(((PokemonExists(&gRecruitedPokemonRef->pokemon[index])))){
            if(IsMonPartner(&gRecruitedPokemonRef->pokemon[index])) {
                return &gRecruitedPokemonRef->pokemon[index];
            }
        }
    }
    return NULL;
}

Pokemon * sub_808D3BC(void)
{
    s32 index;
    for (index = 0; index < NUM_MONSTERS; index++) {
        if (PokemonExists(&gRecruitedPokemonRef->pokemon[index])
            && (gRecruitedPokemonRef->pokemon[index].dungeonLocation.id == DUNGEON_JOIN_LOCATION_LEADER))
        {
            return &gRecruitedPokemonRef->pokemon[index];
        }
    }
    return NULL;
}

Pokemon * sub_808D3F8(void)
{
    s32 index;
    for (index = 0; index < NUM_MONSTERS; index++) {
        if (PokemonExists(&gRecruitedPokemonRef->pokemon[index])
            && (gRecruitedPokemonRef->pokemon[index].dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER))
        {
            return &gRecruitedPokemonRef->pokemon[index];
        }
    }
    return NULL;
}

Pokemon *GetRecruitedMonBySpecies(s16 species_, s32 sameSpeciesCounter)
{
    s32 i;
    s32 species = species_;
    Pokemon *recruitMon = gRecruitedPokemonRef->pokemon;
    s32 counter = 0;

    for (i = 0; i < NUM_MONSTERS; i++, recruitMon++) {
        if (PokemonExists(recruitMon) && recruitMon->speciesNum == species) {
            if (counter == sameSpeciesCounter)
                return recruitMon;
            counter++;
        }
    }
    return NULL;
}

s32 GetFriendSum_808D480(void)
{
    s32 index;
    s32 count;
    Pokemon *pokeStruct;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    count = 0;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonExists(pokeStruct)){
            count++;
        }
    }
    return count;
}

bool8 sub_808D4B0(void)
{
    s32 index;
    Pokemon *pokeStruct;
    bool8 flag;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    flag = FALSE;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonFlag2(pokeStruct) && !IsMonTeamLeader(pokeStruct) && !IsMonPartner(pokeStruct)){
            flag = TRUE;
            pokeStruct->flags &= 0xFFFD;
        }
    }
    return flag;
}

bool8 sub_808D500(void)
{
    s32 index;
    Pokemon *pokeStruct;
    bool8 flag;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    flag = FALSE;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonFlag2(pokeStruct) && !IsMonTeamLeader(pokeStruct)){
            flag = TRUE;
            pokeStruct->flags &= 0xFFFD;
        }
    }
    return flag;
}

s32 GetUnitSum_808D544(s32 *team)
{
    s32 count, i;
    Pokemon *mon = gRecruitedPokemonRef->pokemon;

    count = 0;
    for (i = 0; i < NUM_MONSTERS; i++, mon++) {
        if (PokemonFlag2(mon)) {
            if (team != NULL) {
                team[count] = i;
            }
            count++;
        }
    }

    return count;
}

s32 sub_808D580(s32 *team)
{
    Pokemon *mon;
    s32 index;
    s32 counter;

    mon = gRecruitedPokemonRef->pokemon;
    counter = 0;

    for(index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if (((IsMonTeamLeader(mon)) && (PokemonExists(mon))) && (team != NULL)) {
            team[counter] = index;
            counter++;
            break;
        }
    }

    for(mon = gRecruitedPokemonRef->pokemon, index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if (((IsMonPartner(mon) && !IsMonTeamLeader(mon) && PokemonFlag2(mon)) && (PokemonExists(mon))) &&
            ((((team != NULL)))))
        {
            team[counter] = index;
            counter++;
            break;
        }
    }


    for(mon = gRecruitedPokemonRef->pokemon, index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if ((((PokemonFlag2(mon)) && (PokemonExists(mon))) &&
            (!IsMonTeamLeader(mon))) &&
            (((!IsMonPartner(mon) && (team != NULL))))) {
            team[counter] = index;
            counter++;
        }
    }
    return counter;
}

s32 sub_808D654(s32 *ptr)
{
    s32 i;
    Pokemon *mon = &gRecruitedPokemonRef->pokemon[0];
    s32 count = 0;
    s32 *ptr2;

    for (i = 0, ptr2 = ptr; i < NUM_MONSTERS; i++, mon++) {
        if (PokemonFlag2(mon) && !IsMonTeamLeader(mon) && !IsMonPartner(mon)) {
            if (ptr != NULL) {
                *ptr2 = i;
            }
            ptr2++;
            count++;
        }
    }

    return count;
}

// The same as sub_808D654 except it doesn't exclude partner.
s32 sub_808D6A4(s32 *ptr)
{
    s32 i;
    Pokemon *mon = &gRecruitedPokemonRef->pokemon[0];
    s32 count = 0;
    s32 *ptr2;

    for (i = 0, ptr2 = ptr; i < NUM_MONSTERS; i++, mon++) {
        if (PokemonFlag2(mon) && !IsMonTeamLeader(mon)) {
            if (ptr != NULL) {
                *ptr2 = i;
            }
            ptr2++;
            count++;
        }
    }

    return count;
}

UNUSED static bool8 sub_808D6E8(void)
{
    s32 i;
    s32 count = 0;
    s32 size_count = 0;
    for (i = 0; i < NUM_MONSTERS; i++) {
        Pokemon* pokemon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonExists(pokemon) && PokemonFlag2(pokemon)) {
            size_count += GetBodySize(pokemon->speciesNum);
            count++;
        }
    }
    if ((size_count < 6) && (count < 4)) {
        return 1;
    }
    return 0;
}

bool8 sub_808D750(s32 index_)
{
 Pokemon* pokemon;
 s32 i;
 s32 index = (s16) index_;
 s32 count = 0;
 s32 size_count = 0;

 for (i = 0; i < NUM_MONSTERS; i++) {
     pokemon = &gRecruitedPokemonRef->pokemon[i];
     if (PokemonExists(pokemon) && PokemonFlag2(pokemon)) {
         size_count += GetBodySize(pokemon->speciesNum);
         count++;
     }
 }

 if (count < MAX_TEAM_MEMBERS) {
     pokemon = &gRecruitedPokemonRef->pokemon[index];
     size_count += GetBodySize(pokemon->speciesNum);
     if (size_count <= MAX_TEAM_BODY_SIZE) {
         return TRUE;
     }
 }

 return FALSE;
}

void PeekPokemonItem(s16 index_, BulkItem* item)
{
    s32 index = index_;
    Pokemon* pokemon = &gRecruitedPokemonRef->pokemon[index];
    item->id = pokemon->heldItem.id;
    item->quantity = pokemon->heldItem.quantity;
}

void GivePokemonItem(s16 index_, BulkItem* item)
{
    s32 index = index_;
    Pokemon* pokemon = &gRecruitedPokemonRef->pokemon[index];
    pokemon->heldItem.id = item->id;
    pokemon->heldItem.quantity = item->quantity;
}

bool8 IsPokemonRenamed(Pokemon* pokemon)
{
    char species_name[20];
    char* species = GetMonSpecies(pokemon->speciesNum);
    s32 i;
    CopyStringtoBuffer(species_name, species);
    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        if (pokemon->name[i] != species_name[i]) {
            return FALSE;
        }
        if (!pokemon->name[i]) {
            return TRUE;
        }
    }
    return TRUE;
}

bool8 ComparePokemonNames(s16 a1, s16 a2)
{
    s32 index1 = a1;
    s32 index2 = a2;
    u8* name1 = gRecruitedPokemonRef->pokemon[index1].name;
    u8* name2 = gRecruitedPokemonRef->pokemon[index2].name;

    s32 i;
    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        s32 c1 = ReturnIntFromChar(*name1);
        s32 c2 = ReturnIntFromChar(*name2);
        if (c1 > c2) {
            return TRUE;
        }
        if (c1 < c2) {
            return FALSE;
        }
        name1++;
        name2++;
    }
    return FALSE;
}

void CopyMonsterNameToBuffer(u8 * buffer, s32 index)
{
    s16 index_s16 = index;
    strncpy(buffer, sMonsterParameters[index_s16].species, 0x14);
}

// arm9.bin::0205B274
void CopyYellowMonsterNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    sprintfStatic(buffer, _("{color YELLOW_RAW}%s{reset}"), sMonsterParameters[new_index].species);
}

void CopyCyanMonsterNametoBuffer(u8 *buffer, s32 index_)
{
    s32 index = (s16) index_;
    sprintfStatic(buffer, _("{color CYAN_RAW}%s{reset}"), sMonsterParameters[index].species);
}

void sub_808D930(u8 *buffer, s32 index)
{
  s16 index_s16 = index;

  if (GetBaseSpecies(index_s16) == MONSTER_UNOWN) {
    char *const unownLetters = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?";
    sprintfStatic(buffer,"%s%c",GetMonSpecies(MONSTER_UNOWN),unownLetters[GetUnownIndex(index_s16)]);
  }
  else {
    sprintfStatic(buffer,"%s", sMonsterParameters[index_s16].species);
  }
}

char * GetMonSpecies(s16 index)
{
    return sMonsterParameters[index].species;
}

void PrintColoredPokeNameToBuffer(u8 *buffer, Pokemon *pokemon, s32 colorNum)
{
  u8 nameBuffer [20];

  StrncpyCustom(nameBuffer, pokemon->name, POKEMON_NAME_LENGTH);
  if (colorNum == COLOR_WHITE) {
    colorNum = COLOR_CYAN;
  }
  sprintfStatic(buffer,_("{color}%c%s{reset}"),colorNum,nameBuffer);
}

void sub_808D9DC(u8 *buffer, DungeonMon *param_2, s32 colorNum)
{
  u8 nameBuffer [20];

  StrncpyCustom(nameBuffer, param_2->name, POKEMON_NAME_LENGTH);
  if (colorNum == COLOR_WHITE) {
    colorNum = COLOR_YELLOW;
  }
  sprintfStatic(buffer,_("{color}%c%s{reset}"),colorNum,nameBuffer);
}

void sub_808DA0C(u8 *buffer, DungeonMon *mon)
{
  u8 nameBuffer [20];

  StrncpyCustom(nameBuffer, mon->name, POKEMON_NAME_LENGTH);
  sprintfStatic(buffer,"%s",nameBuffer);
}

void PrintPokeNameToBuffer(u8 *buffer, Pokemon *pokemon)
{
  StrncpyCustom(buffer, pokemon->name, POKEMON_NAME_LENGTH);
}

static const u8 gUnknown_8107645[12] = {
    FALSE,
    TRUE,
    TRUE,
    TRUE,
    TRUE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE,
    FALSE
};

bool8 sub_808DA44(s32 _species, u32 a2_)
{
  // this is the dumbest thing ever, but just making a1 a s16 and
  // a2 a u8 did weird stuff with shifting...
  s32 species = (s16) _species;
  u32 a2 = (u8)a2_;
  if (a2 > 0xc) {
    s32 i;
    struct unkStruct_8107654 data[6] = {
    {MONSTER_JIRACHI, 0xD},
    {MONSTER_RAIKOU, 0xD},
    {MONSTER_ALAKAZAM, 0xE},
    {MONSTER_DUGTRIO, 0xD},
    {MONSTER_DUGTRIO, 0xE},
    {MONSTER_NONE, 0},
  };

    for (i = 0; i < 10 && data[i].species != MONSTER_NONE; i++) {
      if (data[i].species == species && data[i].unk4 == a2) {
        return TRUE;
      }
    }
    return FALSE;
  }
  else {
    return gUnknown_8107645[a2];
  }
}

u8 *GetCategoryString(s16 index)
{
    return sMonsterParameters[index].category;
}

u8 GetBodySize(s32 index)
{
    s16 index_s16 = index;
    return sMonsterParameters[index_s16].bodySize;
}

u8 GetShadowSize(s16 index)
{
    return sMonsterParameters[index].shadowSize;
}

s32 GetMovementSpeed(s16 index)
{
    return sMonsterParameters[index].movementSpeed;
}

u8 GetMovementType(s16 index)
{
    return sMonsterParameters[index].movementType;
}

u8 GetRegenSpeed(s16 index)
{
    return ((u8)(sMonsterParameters[index].regenSpeed) << 25) >> 24;
}

bool8 GetCanMoveFlag(s16 index)
{
    return sMonsterParameters[index].canMove;
}

u8 GetChanceAsleep(s16 index)
{
    return sMonsterParameters[index].chanceAsleep;
}

u32 GetWeight(s16 index)
{
    return sMonsterParameters[index].weight;
}

u32 GetSize(s16 index)
{
    return sMonsterParameters[index].size;
}

u8 GetFriendArea(s32 index)
{
    s16 index_s32 = index;
    return sMonsterParameters[index_s32].friendArea;
}

s32 GetBaseHP(s32 index)
{
    s16 index_s32 = index;
    return sMonsterParameters[index_s32].baseHP;
}

bool8 MonsterIDCanThrowItems(s16 index)
{
    return sMonsterParameters[index].canThrowItems;
}

u8 GetUnk12(s16 index)
{
    return sMonsterParameters[index].unk12;
}

s32 GetPokemonEvolveFrom(s32 index)
{
    s16 index_s16 = index;
    return sMonsterParameters[index_s16].preEvolution.evolveFrom;
}

s32 GetBaseOffensiveStat(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return sMonsterParameters[index_s16].baseAtkSpAtk[r1];
}

s32 GetBaseDefensiveStat(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return sMonsterParameters[index_s16].baseDefSpDef[r1];
}

// arm9.bin::0205AE2C
u8 GetPokemonType(s32 index, u32 typeIndex)
{
    s16 newIndex = index;
    return sMonsterParameters[newIndex].types[typeIndex];
}

u8 GetPokemonAbility(s16 index, u32 abilityIndex)
{
    return sMonsterParameters[index].abilities[abilityIndex];
}

s16 GetDexInternalNo(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return sMonsterParameters[index_s16].dexInternal[r1];
}

s16 GetRecruitRate(s16 index)
{
    return sMonsterParameters[index].recruitRate;
}

s16 GetAlphabetParentNo(s16 index, s32 r1)
{
    return sMonsterParameters[index].alphabetParent[r1];
}

s16 GetInternalNo(s16 index)
{
    return sMonsterParameters[index].dexInternal[1];
}

s32 CalculateEXPGain(s16 index, s32 level)
{
    s32 expYield = sMonsterParameters[index].expYield;
    return expYield + (expYield * (level - 1)) / 10;
}

s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1)
{
    PreEvolution temp2;
    EvolutionRequirements temp1;
    temp1 = sMonsterParameters[index].evolutionRequirements;
    temp2 = sMonsterParameters[index].preEvolution;
    r1->preEvolution = temp2;
    r1->evolutionRequirements = temp1;
    // The return value is not used anywhere, but necessary for the function to match.
    return index;
}

u8 GetPokemonOverworldPalette(s16 index, bool32 recolorShopKecleon)
{
    s32 id = SpeciesId(index);
    if (recolorShopKecleon)
    {
        return 10;
    }
    else
    {
        return sMonsterParameters[id].overworldPalette;
    }
}

OpenedFile *OpenPokemonDialogueSpriteFile(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(sMonsterParameters[index].dialogueSprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, "kao%03d", index);
    return OpenFile(buffer, &gMonsterFileArchive);
}

// arm9.bin::0205AC60
OpenedFile *GetDialogueSpriteDataPtr(s32 index)
{
    // Looks like this loads the dialogue sprite for the pokemon
    char buffer[0xC];
    s16 id = SpeciesId(index);

    if(sMonsterParameters[id].dialogueSprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, "kao%03d", id);
    return OpenFileAndGetFileDataPtr(buffer, &gMonsterFileArchive);
}

bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 spriteId)
{
    // checking to see if dialogue sprite is available??
    return (sMonsterParameters[index].dialogueSprites >> spriteId) & 1;
}

void RecruitedPokemonToDungeonMon(DungeonMon *dst, u32 recruitedPokemonId)
{
    PokemonToDungeonMon(dst, &gRecruitedPokemonRef->pokemon[recruitedPokemonId], recruitedPokemonId);
}

void PokemonToDungeonMon(DungeonMon *dst, Pokemon *src, s32 recruitedPokemonId)
{
    s32 i;

    dst->flags = src->flags;
    dst->level = src->level;
    dst->IQ = src->IQ;
    dst->IQSkills = src->IQSkills;
    GenerateHiddenPower(&dst->hiddenPower);
    dst->dungeonLocation = src->dungeonLocation;
    dst->isTeamLeader = src->isTeamLeader;
    dst->recruitedPokemonId = recruitedPokemonId;
    dst->speciesNum = src->speciesNum;
    dst->tacticIndex = src->tacticIndex;
    dst->unk12 = src->pokeHP;
    dst->unk10 = src->pokeHP;

    for (i = 0; i < 2; i++) {
        dst->offense.att[i] = src->offense.att[i];
        dst->offense.def[i] = src->offense.def[i];
    }

    dst->currExp = src->currExp;
    CopyAndResetMoves(&dst->moves, src->moves);

    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        dst->name[i] = src->name[i];
    }

    if (BulkItemExists(&src->heldItem)) {
        BulkItemToItem(&dst->itemSlot, &src->heldItem);
    }
    else {
        ZeroOutItem(&dst->itemSlot);
    }

    dst->belly = IntToFixedPoint(100);
    dst->maxBelly = IntToFixedPoint(100);
}

void DungeonMonToRecruitedPokemon(s32 id, DungeonMon* src)
{
    DungeonMonToPokemon(&gRecruitedPokemonRef->pokemon[id], src);
}

void DungeonMonToPokemon(Pokemon* dst, DungeonMon* src)
{
    s32 i;

    dst->flags = src->flags;
    dst->level = src->level;
    dst->IQ = src->IQ;
    dst->IQSkills = src->IQSkills;
    dst->dungeonLocation = src->dungeonLocation;
    dst->isTeamLeader = src->isTeamLeader;
    dst->speciesNum = src->speciesNum;
    dst->tacticIndex = src->tacticIndex;
    dst->pokeHP = src->unk12;

    for (i = 0; i < 2; i++) {
        dst->offense.att[i] = src->offense.att[i];
        dst->offense.def[i] = src->offense.def[i];
    }

    dst->currExp = src->currExp;
    CopyBareMoveData(dst->moves, src->moves.moves);

    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        dst->name[i] = src->name[i];
    }

    if (src->itemSlot.flags & ITEM_FLAG_EXISTS) {
        ItemToBulkItem(&dst->heldItem, &src->itemSlot);
    }
    else {
        dst->heldItem.id = ITEM_NOTHING;
    }
}

void sub_808DFDC(s32 a1, DungeonMon* a2)
{
    // transfer item from unk to pokemon at index
    Pokemon* pokemon = &gRecruitedPokemonRef->pokemon[a1];
    if (a2->itemSlot.flags & ITEM_FLAG_EXISTS) {
        ItemToBulkItem(&pokemon->heldItem, &a2->itemSlot);
    }
    else {
        pokemon->heldItem.id = ITEM_NOTHING;
    }
}

void GetLvlUpEntry(LevelData* a1, s32 _id, s32 level)
{
  u8 buffer[12];
  s32 id = SpeciesId(_id);

  if (sLevelCurrentPokeId != id)
  {
    OpenedFile *file;

    sLevelCurrentPokeId = id;
    sprintf(buffer, "lvmp%03d", id);
    file = OpenFileAndGetFileDataPtr(buffer, &gSystemFileArchive);
    DecompressATFile(sLevelCurrentData, 0, file);
    CloseFile(file);
  }
  level -= 1;
  if ( level < 0 )
    level = 0;

   *a1 = sLevelCurrentData[level];
}

const u8* DecompressMoveID(const u8* src, u16* moveID)
{
    u32 byte0;
    u32 byte1 = *src++;
    // If move >= 127 which means it uses 2 bytes and not one
    if (byte1 & 0x80) {
        byte0 = *src++;
    }
    else {
        byte0 = byte1;
        byte1 = 0;
    }

    *moveID = (byte0 & 0x7F) | ((byte1 & 0x7F) << 7);
    return src;
}

s32 GetMovesLearnedAtLevel(u16* dst, s16 species, s32 level, s32 IQPoints)
{
  const u8* stream;
  u16 moveID;  // moveID
  s32 count;
  s32 _species;

  _species = SpeciesId(species);
  count = 0;

  if (species == MONSTER_DECOY) return 0;
  if (species == MONSTER_NONE) return 0;
  if (species == MONSTER_MUNCHLAX) return 0;
  // get stream
  stream = GetLevelUpMoves(_species);

  while (*stream)
  {
    u8 v12;

    // read from stream
    stream = DecompressMoveID(stream, &moveID);
    v12 = *stream++;

    if (v12 > level)
      break;
    if (v12 == level) {
      bool8 cond = TRUE;

      // NOTE: these moves require IQ to be > 333
      if ((moveID == MOVE_FRENZY_PLANT) && (IQPoints < gFrenzyPlantIQReq)) cond = FALSE;
      if ((moveID == MOVE_HYDRO_CANNON) && (IQPoints < gHydroCannonIQReq)) cond = FALSE;
      if ((moveID == MOVE_BLAST_BURN) && (IQPoints < gBlastBurnIQReq)) cond = FALSE;
      if ((moveID == MOVE_VOLT_TACKLE) && (IQPoints < gVoltTackleIQReq)) cond = FALSE;

      if (cond) {
        if (count < 16) {
          *dst++ = moveID;
          ++count;
        }
      }
    }
  }
  return count;
}

bool8 CanMonLearnMove(u16 moveID, s16 _species)
{
  u16 levelUpMoveID;
  u16 HMTMMoveID;
  s32 species = _species;
  const u8* learnsetPtr;

  if (species == MONSTER_DECOY) return 0;
  if (species == MONSTER_NONE) return 0;
  if (species == MONSTER_MUNCHLAX) return 0;
  if (moveID == MOVE_STRUGGLE) return 0;

  learnsetPtr = GetLevelUpMoves(_species);
  while (*learnsetPtr) {
    learnsetPtr = DecompressMoveID(learnsetPtr, &levelUpMoveID);
    learnsetPtr++;
    if (moveID == levelUpMoveID) {
      return TRUE;
    }
  }

  learnsetPtr = GetHMTMMoves(species);
  while (*learnsetPtr) {
    learnsetPtr = DecompressMoveID(learnsetPtr, &HMTMMoveID);
    if (HMTMMoveID == moveID) {
      return TRUE;
    }
  }
  return FALSE;
}

s32 sub_808E218(unkStruct_808E218_arg* a1, Pokemon* pokemon)
{
  s32 i;
  s32 count;
  struct EvolveStage evolve_sequence[3];
  s32 sequence_length;

  count = 0;
  a1->count = 0;
  if (pokemon->speciesNum == MONSTER_DECOY) return 0;
  if (pokemon->speciesNum == MONSTER_NONE) return 0;
  if (pokemon->speciesNum == MONSTER_MUNCHLAX) return 0;

  sequence_length = GetEvolutionSequence(pokemon, evolve_sequence);
  for (i = 0; i < sequence_length; i++) {
    const u8 *ptr;
    u16 result;

    ptr = GetLevelUpMoves(evolve_sequence[i].speciesNum);
    while (*ptr) {
      s32 value;
      ptr = DecompressMoveID(ptr, &result);
      value = *ptr++;

      if (value > evolve_sequence[i].level) {
        break;
      }

      if (count < NUM_MONSTERS) {
        s32 j;
        bool8 cond = 1;

        if ((result == MOVE_FRENZY_PLANT) && (pokemon->IQ < gFrenzyPlantIQReq)) cond = 0;
        if ((result == MOVE_HYDRO_CANNON) && (pokemon->IQ < gHydroCannonIQReq)) cond = 0;
        if ((result == MOVE_BLAST_BURN) && (pokemon->IQ < gBlastBurnIQReq)) cond = 0;
        if ((result == MOVE_VOLT_TACKLE) && (pokemon->IQ < gVoltTackleIQReq)) cond = 0;

        for (j = 0; j < MAX_MON_MOVES; j++) {
          if ((pokemon->moves[j].moveFlags & MOVE_FLAG_EXISTS) && pokemon->moves[j].id == result) {
            cond = 0;
          }
        }

        if (cond) {
          s32 k;
          for (k = 0; k < count && a1->unk0[k] != result; k++) {}

          if (k == count) {
            a1->unk0[count++] = result;
          }
        }
      }
    }
  }

  a1->count = count;
  return count;
}

s32 GetEvolutionSequence(Pokemon* pokemon, EvolveStage* a2)
{
    s32 count;
    s32 species;
    s32 i;

    a2[0].speciesNum = pokemon->speciesNum;
    a2[0].level = pokemon->level;

    count = 1;
    species = pokemon->speciesNum;

    for (i = 0; i < 2; i++) {
        if (!pokemon->unkC[i].level) {
            break;
        }
        species = (s16) GetPokemonEvolveFrom(species);
        if (!species) {
            break;
        }
        a2[count].speciesNum = species;
        a2[count].level = pokemon->unkC[i].level;
        count++;
    }
    return count;
}

s32 sub_808E400(s32 _species, s16* _a2, bool32 _bodySizeCheck, bool32 _shedinjaCheck)
{
    // This is horrible
    s32 species = (s16) (_species);
    bool8 bodySizeCheck = _bodySizeCheck;
    bool8 shedinjaCheck = _shedinjaCheck;
    s32 count = 0;
    s32 i = 1;
    s16 *a2 = _a2;

    for (i = 1; i < MONSTER_MAX; i++) {
        s32 loopSpeciesId = (s16) i;
        s32 loopSpeciesId2 = (s16) loopSpeciesId; // Needed to match

        if (species != (s16) GetPokemonEvolveFrom(loopSpeciesId)) {
            continue;
        }
        if (!bodySizeCheck && GetBodySize(species) != GetBodySize(loopSpeciesId)) {
            continue;
        }
        if (!shedinjaCheck && loopSpeciesId == MONSTER_SHEDINJA) {
            continue;
        }
        *a2++ = loopSpeciesId2;
        count++;
    }
    return count;
}

void sub_808E490(Move* a1, s32 species)
{
    u16 buffer[0x10]; // of moveIDs
    s32 i;
    s16 index_s32 = species;

    s32 count = GetMovesLearnedAtLevel(buffer, index_s32, 1, 999);
    if (count == 0) {
        count = 1;
        buffer[0] = MOVE_ITEM_TOSS;
    }

    i = 0;
    if (i < count) {
        while (i < count) {
            InitZeroedPPPokemonMove(&a1[i], buffer[i]);
            i++;
        }
        i = count;
    }
    while (i < MAX_MON_MOVES) {
        a1[i].moveFlags = 0;
        i++;
    }
}

char* sub_808E4FC(s32 a1)
{
    STATUSTEXTS(statuses);
    PrepareStatusStringArrays(gFormattedStatusNames[a1], statuses);
    return statuses[0]->name;
}

char* sub_808E51C(s32 a1)
{
    STATUSTEXTS(statuses);
    PrepareStatusStringArrays(gFormattedStatusNames[a1], statuses);
    return statuses[0]->desc;
}

struct ShadowSpriteFlags {
    u32 shape;
    u32 size;
    u32 tileNum;
};

static const struct ShadowSpriteFlags gShadowSpriteSizeFlags_8107698[] = {
    [0] = {
        .shape = 0,
        .size = 0,
        .tileNum = 0,
    },
    [1] = {
        .shape = 1,
        .size = 0,
        .tileNum = 1,
    },
    [2] = {
        .shape = 1,
        .size = 1,
        .tileNum = 3,
    },
};

void InitShadowSprites(s32 param_1, s32 param_2)
{
    u8 *vram;
    s32 i, spriteIndex;

    OpenedFile *file = OpenFileAndGetFileDataPtr("etcfont", &gDungeonFileArchive);
    const u8 *src = file->data;
    i = 7;
    src += 4;
    vram = OBJ_VRAM0 + param_1 * 0x20;

    // This loop could be a fakematch, but I couldn't get it work with a regular 'for(i = 0; i < 7; i)' loop.
    while (i != 0)
    {
        CpuCopy(vram, src, 0x20);
        vram += 0x20;
        src += 0x20;
        i--;
    }

    CloseFile(file);

    for (spriteIndex = 0; spriteIndex < 3; spriteIndex++) {
        SpriteOAM *sprite = &sShadowSprites[spriteIndex];

        SpriteSetAffine1(sprite, 0);
        SpriteSetAffine2(sprite, 0);
        SpriteSetObjMode(sprite, 0);
        SpriteSetMosaic(sprite, 0);
        SpriteSetBpp(sprite, 0);
        SpriteSetShape(sprite, gShadowSpriteSizeFlags_8107698[spriteIndex].shape);
        SpriteSetMatrixNum(sprite, 0);
        SpriteSetSize(sprite, gShadowSpriteSizeFlags_8107698[spriteIndex].size);
        SpriteSetTileNum(sprite, gShadowSpriteSizeFlags_8107698[spriteIndex].tileNum + param_1);
        SpriteSetPriority(sprite, param_2);
        SpriteSetPalNum(sprite, 0);
        SpriteSetUnk6_0(sprite, 0);
        SpriteSetUnk6_1(sprite, 0);
    }
}

static const s32 sShadowXPosOffsets[6] = {-4, -8, -16, -4, -8, -16};

bool8 AddShadowSprite(s32 species_, DungeonPos *shadowPos, axdata *axData)
{
    s16 species = (s16) (species_);
    if (species != MONSTER_DIGLETT && species != MONSTER_DUGTRIO) {
        s32 shadowSize = GetShadowSize(species);
        s32 x, y;

        x = shadowPos->x + axData->sub1.shadow.x;
        y = shadowPos->y + axData->sub1.shadow.y;
        x += sShadowXPosOffsets[shadowSize];
        y -= 4;

        SpriteSetX(&sShadowSprites[shadowSize], x);
        SpriteSetY(&sShadowSprites[shadowSize], y);

        AddSprite(&sShadowSprites[shadowSize], 0, NULL, NULL);
    }

    return TRUE;
}
