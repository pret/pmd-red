#ifndef GUARD_POKEMON_H
#define GUARD_POKEMON_H

#include "constants/move.h"
#include "file_system.h"
#include "items.h"
#include "structs/str_pokemon.h"

#define OFFENSE_NRM 0
#define OFFENSE_SP 1

enum PokemonUnk0Flags
{
    POKEMON_FLAG_NONE = 0,
    POKEMON_FLAG_EXISTS = 1 << 0,
    POKEMON_FLAG_ON_TEAM = 1 << 1, // Mon is not on "standby"
    POKEMON_FLAG_x4000 = 1 << 14,
    POKEMON_FLAG_x8000 = 1 << 15,
};

// size: 0x1A4
typedef struct unkStruct_808E218_arg
{
    u16 unk0[NUM_MONSTERS];
    /* 0x1A0 */ u32 count;
} unkStruct_808E218_arg;

// size: 0xC
typedef struct unkStruct_808E218
{
    // leveldata? (same size)
    HiddenPower unk0[3];
} unkStruct_808E218;

extern RecruitedMon *gRecruitedPokemonRef;

void LoadMonsterParameters(void);
RecruitedMon *GetRecruitedPokemon(void);
void InitializeRecruitedPokemon(void);
void CreateLeaderPartnerData(s16 _species, bool32 _isLeader, u8* name);
void CreateLevel1Pokemon(Pokemon *pokemon, s16 _species, u8* name, u32 _itemID, const DungeonLocation *location, u16 *moves);
void sub_808D0D8(Pokemon *pokemon);
void ConvertStoryMonToPokemon(Pokemon *dst, const struct StoryMonData *src);
Pokemon *TryAddPokemonToRecruited(Pokemon*);
Pokemon *sub_808D278(s32 species);
Pokemon *TryAddLevel1PokemonToRecruited(s32 species, u8 *name, u32 _itemID, const DungeonLocation *location, u16 *moveID);
void TryResetPokemonFlags(Pokemon *pokemon);
Pokemon *GetPlayerPokemonStruct(void);
Pokemon *GetPartnerPokemonStruct(void);
Pokemon *sub_808D3BC(void);
Pokemon *sub_808D3F8(void);
Pokemon *GetRecruitedMonBySpecies(s16 species_, s32 sameSpeciesCounter);
s32 GetFriendSum_808D480(void);
bool8 sub_808D4B0(void);
bool8 sub_808D500(void);
s32 GetUnitSum_808D544(s32 *team);
s32 sub_808D580(s32 *team);
s32 sub_808D654(s32 *ptr);
s32 sub_808D6A4(s32 *ptr);
bool8 sub_808D750(s32 index_);
void PeekPokemonItem(s16 index_, BulkItem* item);
void GivePokemonItem(s16 index_, BulkItem* item);
bool8 IsPokemonRenamed(Pokemon* pokemon);
bool8 ComparePokemonNames(s16, s16);
void CopyMonsterNameToBuffer(u8 * buffer, s32 index);
void CopyYellowMonsterNametoBuffer(u8 *buffer, s16 index);
void CopyCyanMonsterNametoBuffer(u8 *buffer, s32 index_);
void sub_808D930(u8 *buffer, s32 index);
char * GetMonSpecies(s16 index);
void PrintColoredPokeNameToBuffer(u8 *buffer, Pokemon *pokemon, s32 colorNum);
void sub_808D9DC(u8 *buffer, DungeonMon *, s32 colorNum);
void sub_808DA0C(u8 *buffer, DungeonMon *);
void PrintPokeNameToBuffer(u8 *buffer, Pokemon *pokemon);
bool8 sub_808DA44(s32 _species, u32 a2_);
u8 *GetCategoryString(s16 index);
u8 GetBodySize(s32 index);
u8 GetShadowSize(s16 index);
s32 GetMovementSpeed(s16 index);
u8 GetMovementType(s16 index);
u8 GetRegenSpeed(s16 index);
bool8 GetCanMoveFlag(s16 index);
u8 GetChanceAsleep(s16 index);
u32 GetWeight(s16 index);
u32 GetSize(s16 index);
u8 GetFriendArea(s32 index);
s32 GetBaseHP(s32 index);
bool8 MonsterIDCanThrowItems(s16 index);
u8 GetUnk12(s16 index);
s32 GetPokemonEvolveFrom(s32 index);
s32 GetBaseOffensiveStat(s32 index, u32 r1);
s32 GetBaseDefensiveStat(s32 index, u32 r1);
u8 GetPokemonType(s32 index, u32 typeIndex);
u8 GetPokemonAbility(s16 index, u32 abilityIndex);
s16 GetDexInternalNo(s32 index, u32 r1);
s16 GetRecruitRate(s16 index);
s16 GetAlphabetParentNo(s16 index, s32 r1);
s16 GetInternalNo(s16 index);
s32 CalculateEXPGain(s16 index, s32 level);
s16 GetPokemonEvolveConditions(s16 index, unkEvolve *r1);
u8 GetPokemonOverworldPalette(s16 index, bool32 recolorShopKecleon);
OpenedFile *OpenPokemonDialogueSpriteFile(s16 index);
OpenedFile *GetDialogueSpriteDataPtr(s32 index);
bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 spriteId);
void RecruitedPokemonToDungeonMon(DungeonMon *dst, u32 recruitedPokemonId);
void PokemonToDungeonMon(DungeonMon *dst, Pokemon *src, s32 recruitedPokemonId);
void DungeonMonToRecruitedPokemon(s32 id, DungeonMon* src);
void DungeonMonToPokemon(Pokemon* dst, DungeonMon* src);
void sub_808DFDC(s32 a1, DungeonMon* a2);
void GetLvlUpEntry(LevelData* a1, s32 _id, s32 level);
const u8* DecompressMoveID(const u8* a1, u16* moveID);
s32 GetMovesLearnedAtLevel(u16* dst, s16 species, s32 level, s32 IQPoints);
bool8 CanMonLearnMove(u16 moveID, s16 _species);
s32 sub_808E218(unkStruct_808E218_arg* a1, Pokemon* pokemon);
s32 GetEvolutionSequence(Pokemon* pokemon, EvolveStage* a2);
s32 sub_808E400(s32 _species, s16* _a2, bool32 _bodySizeCheck, bool32 _shedinjaCheck);
void InitializeLevel1MovesBySpecies(Move* moves, s32 species);
char* sub_808E4FC(s32 a1);
char* sub_808E51C(s32 a1);
void InitShadowSprites(s32 param_1, s32 param_2);
bool8 AddShadowSprite(s32 species_, DungeonPos *shadowPos, axdata *axData);

static inline bool8 PokemonExists(Pokemon *mon)
{
    return (mon->flags & POKEMON_FLAG_EXISTS) != 0;
}

static inline bool8 DungeonMonExists(DungeonMon *mon)
{
    return (mon->flags & POKEMON_FLAG_EXISTS) != 0;
}

static inline bool8 PokemonFlag2(Pokemon *mon)
{
    return (mon->flags & POKEMON_FLAG_ON_TEAM) != 0;
}

static inline bool8 PokemonFlag2Struct2(DungeonMon *mon)
{
    return (mon->flags & POKEMON_FLAG_ON_TEAM) != 0;
}

static inline void SetPokemonFlag2(Pokemon *mon)
{
    mon->flags |= POKEMON_FLAG_ON_TEAM;
}

static inline bool8 IsMonTeamLeader(Pokemon *pokemon)
{
    return pokemon->isTeamLeader != FALSE;
}

#include "constants/dungeon.h"

static inline bool8 IsMonPartner(Pokemon *mon)
{
    return (mon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_PARTNER);
}

static inline bool8 IsMonLeader(Pokemon *mon)
{
    return (mon->dungeonLocation.id == DUNGEON_JOIN_LOCATION_LEADER);
}

// Needed to match a couple of functions which use species id.
// The theory is that there was some internal species conversion which got scrapped later on.
static inline s16 SpeciesId(s32 id)
{
    return id;
}

#endif // GUARD_POKEMON_H
