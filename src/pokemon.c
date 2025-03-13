#include "global.h"
#include "globaldata.h"
#include "pokemon.h"
#include "code_800D090.h"
#include "code_8097DD0.h"
#include "constants/colors.h"
#include "constants/monster.h"
#include "constants/tactic.h"
#include "decompress.h"
#include "file_system.h"
#include "pokemon_3.h"
#include "text_util.h"
#include "moves.h"
#include "friend_area.h"
#include "exclusive_pokemon.h"
#include "cpu.h"

extern struct FileArchive gSystemFileArchive;

static EWRAM_DATA MonsterDataEntry *gMonsterParameters = {0};
static EWRAM_DATA OpenedFile *gMonsterParametersFile = {0};
static EWRAM_DATA SpriteOAM gShadowSprites[3] = {0};
static EWRAM_DATA unkStruct_203B45C gRecruitedPokemon = {0};
static EWRAM_DATA u16 gLevelCurrentPokeId = {0};
UNUSED static EWRAM_DATA u16 unused_data[3] = {0};
static EWRAM_DATA LevelData gLevelCurrentData[0x64] = {0};

EWRAM_INIT unkStruct_203B45C *gRecruitedPokemonRef = {NULL};

struct unkStruct_8107654 {
    s16 species;
    s32 unk4;
};

ALIGNED(4) static const char sMonsterParameterFileName[] = "monspara";
ALIGNED(4) static const char gUnknown_8107600[] = _("{color YELLOW_RAW}%s{reset}");
ALIGNED(4) static const char gUnknown_8107608[] = _("{color CYAN_RAW}%s{reset}");
ALIGNED(4) static const char gUnownLetters[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ!?";
ALIGNED(4) static const char gUnknown_8107630[] = "%s%c";
ALIGNED(4) static const char gUnknown_8107638[] = "%s";
ALIGNED(4) static const char gUnknown_810763C[] = _("{color}%c%s{reset}");
static const u8 gUnknown_8107645[12] = {0x00, 0x01, 0x01, 0x01, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00};

extern s16 gFrenzyPlantIQReq;  // 0x14d
extern s16 gHydroCannonIQReq;  // 0x14d
extern s16 gBlastBurnIQReq;  // 0x14d
extern s16 gVoltTackleIQReq;  // 0x14d
extern char* gFormattedStatusNames[];

extern int sprintf(char *, const char *, ...);
extern u32 ReturnIntFromChar(u8 r0);
extern void xxx_pokemon2_to_pokemonstruct_808DF44(PokemonStruct1*, PokemonStruct2*);

void LoadMonsterParameters(void)
{
    gRecruitedPokemonRef = &gRecruitedPokemon;
    gMonsterParametersFile = OpenFileAndGetFileDataPtr(sMonsterParameterFileName, &gSystemFileArchive);
    gMonsterParameters = (MonsterDataEntry *)gMonsterParametersFile->data;
    gLevelCurrentPokeId = 0;
}

unkStruct_203B45C *GetRecruitedPokemon(void)
{
    return &gRecruitedPokemon;
}

void InitializeRecruitedPokemon(void)
{
  s32 index;

  for(index = 0; index < NUM_MONSTERS; index++)
  {
    gRecruitedPokemonRef->pokemon[index].unk0 = 0;
  }

  for(index = 0; index < 4; index++)
  {
    gRecruitedPokemonRef->pokemon2[index].unk0 = 0;
  }

  for(index = 0; index < MAX_TEAM_MEMBERS; index++)
  {
    gRecruitedPokemonRef->team[index].speciesNum = 0;
    gRecruitedPokemonRef->team[index].unk0 = 0;
  }
}

void sub_808CE74(s16 _species, bool32 _isLeader, u8* name)
{
     struct PokemonStruct1 pokemon;
     u8 name_buffer[20];
     u32 friendArea;
     s32 i;
     s32 species = _species;
     bool8 isLeader = _isLeader;

     pokemon.unk0 = 3;
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
     friendArea = gMonsterParameters[species].friendArea;
     for (i = 0; i < NUM_MONSTERS; i++) {
         if (!PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
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

void sub_808CFD0(PokemonStruct1 *pokemon, s16 _species, u8* name, u32 _itemID, DungeonLocation *location, u16 *moveID)
{
    u8 name_buffer[20];
    s32 i;

    s32 species = _species;
    u8 itemID = _itemID;

    pokemon->unk0 = 1;
    pokemon->isTeamLeader = 0;
    pokemon->level = 1;
    pokemon->pokeHP = GetBaseHP(species);
    pokemon->offense.att[0] = GetBaseOffensiveStat(species, 0);
    pokemon->offense.att[1] = GetBaseOffensiveStat(species, 1);
    pokemon->offense.def[0] = GetBaseDefensiveStat(species, 0);
    pokemon->offense.def[1] = GetBaseDefensiveStat(species, 1);
    pokemon->speciesNum = species;
    xxx_init_helditem_8090B08(&pokemon->heldItem, itemID);
    pokemon->currExp = 0;
    pokemon->tacticIndex = TACTIC_LETS_GO_TOGETHER;
    pokemon->IQ = 1;
    pokemon->dungeonLocation = *location;
    pokemon->unkC[0].level = 0;
    pokemon->unkC[1].level = 0;
    SetDefaultIQSkills(&pokemon->IQSkills, FALSE);

    if(moveID != NULL)
    {
        for(i = 0; i < MAX_MON_MOVES; i++)
        {
            if(moveID[i] != 0)
            {
                InitZeroedPPPokemonMove(&pokemon->moves[i], moveID[i]);
            }
            else
            {
                pokemon->moves[i].moveFlags = 0;
            }
        }
    }
    else
    {
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

void sub_808D0D8(PokemonStruct1 *pokemon)
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

void sub_808D144(PokemonStruct1 *pokemon, struct unkStruct_808D144 *r1)
{
    s32 i;

    pokemon->unk0 = 1;
    pokemon->isTeamLeader = FALSE;
    pokemon->level = r1->level;
    pokemon->pokeHP = r1->pokeHP;
    pokemon->offense.att[0] = r1->offenseAtk[0];
    pokemon->offense.att[1] = r1->offenseAtk[1];
    pokemon->offense.def[0] = r1->offenseDef[0];
    pokemon->offense.def[1] = r1->offenseDef[1];
    pokemon->speciesNum = r1->speciesNum;
    xxx_init_helditem_8090B08(&pokemon->heldItem, r1->itemID);
    pokemon->currExp = r1->currExp;
    pokemon->tacticIndex = TACTIC_LETS_GO_TOGETHER;
    pokemon->IQ = r1->IQ;
    pokemon->dungeonLocation = r1->dungeonLocation;
    pokemon->unkC[0].level = 0;
    pokemon->unkC[1].level = 0;
    SetDefaultIQSkills(&pokemon->IQSkills, FALSE);

    for(i = 0; i < MAX_MON_MOVES; i++)
    {
        if(r1->moveID[i] != 0)
        {
            InitZeroedPPPokemonMove(&pokemon->moves[i], r1->moveID[i]);
        }
        else
        {
            pokemon->moves[i].moveFlags = 0;
        }
    }

    for(i = 0; i < POKEMON_NAME_LENGTH; i++)
    {
        pokemon->name[i] = r1->name[i];
    }
}


PokemonStruct1 *sub_808D1DC(PokemonStruct1 *pokemon)
{
    u32 friendArea;
    s32 i;

    s32 species  = pokemon->speciesNum;
    friendArea = gMonsterParameters[species].friendArea;

    if(!gFriendAreas[friendArea]) return NULL;
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (!PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
            u8 speciesFriendArea = sub_80923D4(i);
            if (speciesFriendArea == friendArea) {
                gRecruitedPokemonRef->pokemon[i] = *pokemon;
                gRecruitedPokemonRef->pokemon[i].unk0 &= 0xbfff;
                sub_80980B4(pokemon->speciesNum);
                return &gRecruitedPokemonRef->pokemon[i];
            }
        }
    }
    return NULL;
}

PokemonStruct1 *sub_808D278(s16 species, PokemonStruct1 *pokemon)
{
    u32 friendArea;
    s32 i;

    friendArea = gMonsterParameters[species].friendArea;

    if(!gFriendAreas[friendArea]) return NULL;
    for (i = 0; i < NUM_MONSTERS; i++) {
        if (!PokemonFlag1(&gRecruitedPokemonRef->pokemon[i])) {
            u8 speciesFriendArea = sub_80923D4(i);
            if (speciesFriendArea == friendArea) {
                return &gRecruitedPokemonRef->pokemon[i];
            }
        }
    }
    return NULL;
}

PokemonStruct1 *sub_808D2E8(s32 species, u8 *name, u32 _itemID, DungeonLocation *location, u16 *moveID)
{
    PokemonStruct1 pokemon;

    sub_808CFD0(&pokemon, species, name, (u8)_itemID, location, moveID);
    return sub_808D1DC(&pokemon);
}

void sub_808D31C(PokemonStruct1 *param_1)
{
  if ((!IsMonTeamLeader(param_1)) && !IsMonPartner(param_1))
      param_1->unk0 = 0;
}

PokemonStruct1 * GetPlayerPokemonStruct(void)
{
    s32 index;

    for(index = 0; index < NUM_MONSTERS; index++)
    {
        if(((PokemonFlag1(&gRecruitedPokemonRef->pokemon[index])))){
            if(IsMonTeamLeader(&gRecruitedPokemonRef->pokemon[index])) {
                return &gRecruitedPokemonRef->pokemon[index];
            }
        }
    }
    return NULL;
}

PokemonStruct1 * sub_808D378(void)
{
    s32 index;

    for(index = 0; index < NUM_MONSTERS; index++)
    {
        if(((PokemonFlag1(&gRecruitedPokemonRef->pokemon[index])))){
            if(IsMonPartner(&gRecruitedPokemonRef->pokemon[index])) {
                return &gRecruitedPokemonRef->pokemon[index];
            }
        }
    }
    return NULL;
}

PokemonStruct1 * sub_808D3BC(void)
{
    s32 index;
    for (index = 0; index < NUM_MONSTERS; index++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[index])
            && (gRecruitedPokemonRef->pokemon[index].dungeonLocation.id == DUNGEON_JOIN_LOCATION_LEADER))
        {
            return &gRecruitedPokemonRef->pokemon[index];
        }
    }
    return NULL;
}

PokemonStruct1 * sub_808D3F8(void)
{
    s32 index;
    for (index = 0; index < NUM_MONSTERS; index++) {
        if (PokemonFlag1(&gRecruitedPokemonRef->pokemon[index])
            && (gRecruitedPokemonRef->pokemon[index].dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER))
        {
            return &gRecruitedPokemonRef->pokemon[index];
        }
    }
    return NULL;
}

PokemonStruct1 * sub_808D434(s16 species, s32 param_2)
{
    PokemonStruct1 *pokeStruct;
    s32 index;
    s32 counter;
    s32 species_s32 = species;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    counter = 0;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(((PokemonFlag1(pokeStruct)) && (pokeStruct->speciesNum == species_s32))) {
            if (counter == param_2)
                return pokeStruct;
            counter++;
        }
    }
    return NULL;
}

s32 GetFriendSum_808D480(void)
{
    s32 index;
    s32 count;
    PokemonStruct1 *pokeStruct;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    count = 0;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonFlag1(pokeStruct)){
            count++;
        }
    }
    return count;
}

bool8 sub_808D4B0(void)
{
    s32 index;
    PokemonStruct1 *pokeStruct;
    bool8 flag;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    flag = FALSE;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonFlag2(pokeStruct) && !IsMonTeamLeader(pokeStruct) && !IsMonPartner(pokeStruct)){
            flag = TRUE;
            pokeStruct->unk0 &= 0xFFFD;
        }
    }
    return flag;
}

bool8 sub_808D500(void)
{
    s32 index;
    PokemonStruct1 *pokeStruct;
    bool8 flag;

    pokeStruct = gRecruitedPokemonRef->pokemon;
    flag = FALSE;
    for(index = 0; index < NUM_MONSTERS; index++, pokeStruct++)
    {
        if(PokemonFlag2(pokeStruct) && !IsMonTeamLeader(pokeStruct)){
            flag = TRUE;
            pokeStruct->unk0 &= 0xFFFD;
        }
    }
    return flag;
}

s32 GetUnitSum_808D544(s32 *team)
{
    s32 count, i;
    PokemonStruct1 *mon = gRecruitedPokemonRef->pokemon;

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
    PokemonStruct1 *mon;
    s32 index;
    s32 counter;

    mon = gRecruitedPokemonRef->pokemon;
    counter = 0;

    for(index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if (((IsMonTeamLeader(mon)) && (PokemonFlag1(mon))) && (team != NULL)) {
            team[counter] = index;
            counter++;
            break;
        }
    }

    for(mon = gRecruitedPokemonRef->pokemon, index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if (((IsMonPartner(mon) && !IsMonTeamLeader(mon) && PokemonFlag2(mon)) && (PokemonFlag1(mon))) &&
            ((((team != NULL)))))
        {
            team[counter] = index;
            counter++;
            break;
        }
    }


    for(mon = gRecruitedPokemonRef->pokemon, index = 0; index < NUM_MONSTERS; index++, mon++)
    {
        if ((((PokemonFlag2(mon)) && (PokemonFlag1(mon))) &&
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
    PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[0];
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
    PokemonStruct1 *mon = &gRecruitedPokemonRef->pokemon[0];
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

bool8 sub_808D6E8()
{
    s32 i;
    s32 count = 0;
    s32 size_count = 0;
    for (i = 0; i < NUM_MONSTERS; i++) {
        PokemonStruct1* pokemon = &gRecruitedPokemonRef->pokemon[i];
        if (PokemonFlag1(pokemon) && PokemonFlag2(pokemon)) {
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
     PokemonStruct1* pokemon;
     s32 i;
     s32 index = (s16) index_;
     s32 count = 0;
     s32 size_count = 0;

     for (i = 0; i < 413; i++) {
         pokemon = &gRecruitedPokemonRef->pokemon[i];
         if (PokemonFlag1(pokemon) && PokemonFlag2(pokemon)) {
             size_count += GetBodySize(pokemon->speciesNum);
             count++;
         }
     }

     if (count < 4) {
         pokemon = &gRecruitedPokemonRef->pokemon[index];
         size_count += GetBodySize(pokemon->speciesNum);
         if (size_count < 7) {
             return TRUE;
         }
     }

     return FALSE;
 }

void PeekPokemonItem(s16 index_, BulkItem* item) {
    s32 index = index_;
    PokemonStruct1* pokemon = &gRecruitedPokemonRef->pokemon[index];
    item->id = pokemon->heldItem.id;
    item->quantity = pokemon->heldItem.quantity;
}

void GivePokemonItem(s16 index_, BulkItem* item) {
    s32 index = index_;
    PokemonStruct1* pokemon = &gRecruitedPokemonRef->pokemon[index];
    pokemon->heldItem.id = item->id;
    pokemon->heldItem.quantity = item->quantity;
}

bool8 IsPokemonRenamed(PokemonStruct1* pokemon) {
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
    strncpy(buffer, gMonsterParameters[index_s16].species, 0x14);
}

void CopyYellowMonsterNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    sprintfStatic(buffer, gUnknown_8107600, gMonsterParameters[new_index].species); // {color YELLOW}%s{reset}
}

void CopyCyanMonsterNametoBuffer(u8 *buffer, s16 index)
{
    s32 new_index = index;
    sprintfStatic(buffer, gUnknown_8107608, gMonsterParameters[new_index].species); // {color CYAN}%s{reset}
}

void sub_808D930(u8 *buffer, s32 index)
{
  char *unownString;
  s32 unownIndex;
  const char *preload;
  s16 index_s16 = index;

  if (GetBaseSpecies(index_s16) == MONSTER_UNOWN) {
    preload = gUnknown_8107630; // %s%c
    unownString = GetMonSpecies(MONSTER_UNOWN);
    unownIndex = GetUnownIndex(index_s16);
    sprintfStatic(buffer,preload,unownString,gUnownLetters[unownIndex]); // ABCDEFGHIJKLMNOPQRSTUVWXYZ!?
  }
  else {
    sprintfStatic(buffer,gUnknown_8107638, gMonsterParameters[index_s16].species); // %s
  }
}

char * GetMonSpecies(s16 index)
{
    return gMonsterParameters[index].species;
}

void PrintColoredPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon, s32 colorNum)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, pokemon->name, POKEMON_NAME_LENGTH);
  if (colorNum == COLOR_WHITE) {
    colorNum = COLOR_CYAN;
  }
  sprintfStatic(buffer,gUnknown_810763C,colorNum,nameBuffer); // {color}%c%s{reset}
}

void sub_808D9DC(u8 *buffer, PokemonStruct2 *param_2, s32 colorNum)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, param_2->name, POKEMON_NAME_LENGTH);
  if (colorNum == COLOR_WHITE) {
    colorNum = COLOR_YELLOW;
  }
  sprintfStatic(buffer,gUnknown_810763C,colorNum,nameBuffer); // {color}%c%s{reset}
}

void sub_808DA0C(u8 *buffer, PokemonStruct2 *param_2)
{
  u8 nameBuffer [20];

  sub_80922B4(nameBuffer, param_2->name, POKEMON_NAME_LENGTH);
  sprintfStatic(buffer,gUnknown_8107638,nameBuffer); // %s
}

void PrintPokeNameToBuffer(u8 *buffer, PokemonStruct1 *pokemon)
{
  sub_80922B4(buffer, pokemon->name, POKEMON_NAME_LENGTH);
}

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
        return 1;
      }
    }
    return 0;
  }
  else {
    return gUnknown_8107645[a2];
  }
}

u8 *GetCategoryString(s16 index)
{
    return gMonsterParameters[index].category;
}

u8 GetBodySize(s32 index)
{
    s16 index_s16 = index;
    return gMonsterParameters[index_s16].bodySize;
}

u8 GetShadowSize(s16 index)
{
    return gMonsterParameters[index].shadowSize;
}

s32 GetMovementSpeed(s16 index)
{
    return gMonsterParameters[index].movementSpeed;
}

u8 GetMovementType(s16 index)
{
    return gMonsterParameters[index].movementType;
}

u8 GetRegenSpeed(s16 index)
{
    return ((u8)(gMonsterParameters[index].regenSpeed) << 25) >> 24;
}

bool8 GetCanMoveFlag(s16 index)
{
    return gMonsterParameters[index].canMove;
}

u8 GetChanceAsleep(s16 index)
{
    return gMonsterParameters[index].chanceAsleep;
}

u32 GetWeight(s16 index)
{
    return gMonsterParameters[index].weight;
}

u32 GetSize(s16 index)
{
    return gMonsterParameters[index].size;
}

u8 GetFriendArea(s32 index)
{
    s16 index_s32 = index;
    return gMonsterParameters[index_s32].friendArea;
}

s32 GetBaseHP(s32 index)
{
    s16 index_s32 = index;
    return gMonsterParameters[index_s32].baseHP;
}

bool8 MonsterIDCanThrowItems(s16 index)
{
    return gMonsterParameters[index].canThrowItems;
}

u8 GetUnk12(s16 index)
{
    return gMonsterParameters[index].unk12;
}

s32 GetPokemonEvolveFrom(s32 index)
{
    s16 index_s16 = index;
    return gMonsterParameters[index_s16].preEvolution.evolveFrom;
}

s32 GetBaseOffensiveStat(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return gMonsterParameters[index_s16].baseAtkSpAtk[r1];
}

s32 GetBaseDefensiveStat(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return gMonsterParameters[index_s16].baseDefSpDef[r1];
}

u8 GetPokemonType(s32 index, u32 typeIndex)
{
    s16 newIndex = index;
    return gMonsterParameters[newIndex].types[typeIndex];
}

u8 GetPokemonAbility(s16 index, u32 abilityIndex)
{
    return gMonsterParameters[index].abilities[abilityIndex];
}

s16 GetDexInternalNo(s32 index, u32 r1)
{
    s16 index_s16 = index;
    return gMonsterParameters[index_s16].dexInternal[r1];
}

s16 GetRecruitRate(s16 index)
{
    return gMonsterParameters[index].recruitRate;
}

s16 GetAlphabetParentNo(s16 index, s32 r1)
{
    return gMonsterParameters[index].alphabetParent[r1];
}


s16 GetInternalNo(s16 index)
{
    return gMonsterParameters[index].dexInternal[1];
}

s32 CalculateEXPGain(s16 index, s32 level)
{
    s32 expYield = gMonsterParameters[index].expYield;
    return expYield + (expYield * (level - 1)) / 10;
}

s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1)
{
    PreEvolution temp2;
    EvolutionRequirements temp1;
    temp1 = gMonsterParameters[index].evolutionRequirements;
    temp2 = gMonsterParameters[index].preEvolution;
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
        return gMonsterParameters[id].overworldPalette;
    }
}

OpenedFile *OpenPokemonDialogueSpriteFile(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[index].dialogueSprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, "kao%03d", index);
    return OpenFile(buffer, &gMonsterFileArchive);
}

OpenedFile *GetDialogueSpriteDataPtr(s32 index)
{
    // Looks like this loads the dialogue sprite for the pokemon
    char buffer[0xC];
    s16 id = SpeciesId(index);

    if(gMonsterParameters[id].dialogueSprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, "kao%03d", id);
    return OpenFileAndGetFileDataPtr(buffer, &gMonsterFileArchive);
}

bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 spriteId)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[index].dialogueSprites >> spriteId) & 1;
}

void xxx_pokemonstruct_index_to_pokemon2_808DE30(void* r0, u32 r1)
{
    xxx_pokemonstruct_to_pokemon2_808DE50(r0, &gRecruitedPokemonRef->pokemon[r1], r1);
}

void xxx_pokemonstruct_to_pokemon2_808DE50(PokemonStruct2 * a1, PokemonStruct1 *pokemon, s32 a3)
{
    s32 i;
    BulkItem* held;
    Item* slot;

    a1->unk0 = pokemon->unk0;
    a1->level = pokemon->level;
    a1->IQ = pokemon->IQ;
    a1->IQSkills = pokemon->IQSkills;
    GenerateHiddenPower(&a1->hiddenPower);
    a1->dungeonLocation = pokemon->dungeonLocation;
    a1->isTeamLeader = pokemon->isTeamLeader;
    a1->unkA = a3;
    a1->speciesNum = pokemon->speciesNum;
    a1->tacticIndex = pokemon->tacticIndex;
    a1->unk12 = pokemon->pokeHP;
    a1->unk10 = pokemon->pokeHP;

    for (i = 0; i < 2; i++) {
        a1->offense.att[i] = pokemon->offense.att[i];
        a1->offense.def[i] = pokemon->offense.def[i];
    }

    a1->currExp = pokemon->currExp;
    CopyAndResetMoves(&a1->moves, pokemon->moves);

    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        a1->name[i] = pokemon->name[i];
    }

    held = &pokemon->heldItem;
    slot = &a1->itemSlot;

    if ((u32)(-held->id | held->id) >> 31) {
        HeldItemToSlot(slot, held);
    }
    else {
        slot->id = ITEM_NOTHING;
        slot->quantity = 0;
        slot->flags = 0;
    }

    a1->belly = IntToFixedPoint(100);
    a1->maxBelly = IntToFixedPoint(100);
}

void xxx_pokemon2_to_pokemonstruct_index_808DF2C(s32 a1, PokemonStruct2* a2)
{
    xxx_pokemon2_to_pokemonstruct_808DF44(&a1[gRecruitedPokemonRef->pokemon], a2);
}


void xxx_pokemon2_to_pokemonstruct_808DF44(PokemonStruct1* pokemon, PokemonStruct2* a2)
{
    s32 i;

    pokemon->unk0 = a2->unk0;
    pokemon->level = a2->level;
    pokemon->IQ = a2->IQ;
    pokemon->IQSkills = a2->IQSkills;
    pokemon->dungeonLocation = a2->dungeonLocation;
    pokemon->isTeamLeader = a2->isTeamLeader;
    pokemon->speciesNum = a2->speciesNum;
    pokemon->tacticIndex = a2->tacticIndex;
    pokemon->pokeHP = a2->unk12;

    for (i = 0; i < 2; i++) {
        pokemon->offense.att[i] = a2->offense.att[i];
        pokemon->offense.def[i] = a2->offense.def[i];
    }

    pokemon->currExp = a2->currExp;
    CopyBareMoveData(pokemon->moves, a2->moves.moves);

    for (i = 0; i < POKEMON_NAME_LENGTH; i++) {
        pokemon->name[i] = a2->name[i];
    }

    if (a2->itemSlot.flags & ITEM_FLAG_EXISTS) {
        SlotToHeldItem(&pokemon->heldItem, &a2->itemSlot);
    }
    else {
        pokemon->heldItem.id = ITEM_NOTHING;
    }
}

void sub_808DFDC(s32 a1, PokemonStruct2* a2)
{
    // transfer item from unk to pokemon at index
    PokemonStruct1* pokemon = &gRecruitedPokemonRef->pokemon[a1];
    if (a2->itemSlot.flags & ITEM_FLAG_EXISTS) {
        SlotToHeldItem(&pokemon->heldItem, &a2->itemSlot);
    }
    else {
        pokemon->heldItem.id = ITEM_NOTHING;
    }
}

void GetPokemonLevelData(LevelData* a1, s32 _id, s32 level)
{
  u8 buffer[12];
  s32 id = SpeciesId(_id);

  if ((s16)gLevelCurrentPokeId != id)
  {
    OpenedFile *file;

    gLevelCurrentPokeId = id;
    sprintf(buffer, "lvmp%03d", id);
    file = OpenFileAndGetFileDataPtr(buffer, &gSystemFileArchive);
    DecompressATFile(gLevelCurrentData, 0, file);
    CloseFile(file);
  }
  level -= 1;
  if ( level < 0 )
    level = 0;

   *a1 = gLevelCurrentData[level];
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
  s32 species = _species;  // r4
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


s32 sub_808E218(unkStruct_808E218_arg* a1, PokemonStruct1* pokemon)
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

s32 GetEvolutionSequence(PokemonStruct1* pokemon, struct EvolveStage* a2)
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

extern const struct FileArchive gDungeonFileArchive;

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
        SpriteOAM *sprite = &gShadowSprites[spriteIndex];

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

static const s32 gUnknown_81076C4[6] = {-4, -8, -16, -4, -8, -16}; // x-coord positioning for shadow sprites

bool8 AddShadowSprite(s16 species, s16* a2, s16* a3)
{
    if (species != MONSTER_DIGLETT && species != MONSTER_DUGTRIO) {
        s32 shadowSize = GetShadowSize(species);
        s32 x, y;

        x = a2[0] + a3[8];
        y = a2[1] + a3[9];
        x += gUnknown_81076C4[shadowSize];
        y -= 4;

        SpriteSetX(&gShadowSprites[shadowSize], x);
        SpriteSetY(&gShadowSprites[shadowSize], y);

        AddSprite(&gShadowSprites[shadowSize], 0, NULL, NULL);
    }

    return TRUE;
}
