#include "global.h"
#include "pokemon.h"

extern struct MonsterDataEntry *gMonsterParameters;
extern bool8 *gFriendAreas;
void SetDefaultIQSkills(u8 *param_1, bool8 enableSelfCurer);
void sub_808E490(struct Move* a1, s32 species);
void BoundedCopyStringtoBuffer(u8 *, u8 *, u32);
void sub_80980B4(s32);
u8 sub_80923D4(s32);

#define DUNGEON_JOIN_LOCATION_LEADER 64
#define DUNGEON_JOIN_LOCATION_PARTNER 65

 void sub_808CE74(s16 _species, bool8 _isLeader, u8* name)  
 {
     struct PokemonStruct pokemon;
     struct PokemonStruct *temp;
     u8 name_buffer[20];
     u32 friendArea;
     s32 i;
     s32 species = _species;
     bool32 isLeader = _isLeader << 24;

     pokemon.unk0 = 3;
     if (isLeader) {
         pokemon.isTeamLeader = TRUE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_LEADER; 
     }
     else {
         pokemon.isTeamLeader = FALSE;
         pokemon.dungeonLocation.id = DUNGEON_JOIN_LOCATION_PARTNER;
     }
     pokemon.unkHasNextStage = 1;
     pokemon.pokeHP = GetBaseHP(species);
     pokemon.offense.att[0] = GetBaseOffensiveStat(species, 0);
     pokemon.offense.att[1] = GetBaseOffensiveStat(species, 1);
     pokemon.offense.def[0] = GetBaseDefensiveStat(species, 0);
     pokemon.offense.def[1] = GetBaseDefensiveStat(species, 1);
     pokemon.IQ = 1;
     pokemon.unkC[0].unk0 = 0;
     pokemon.unkC[1].unk0 = 0;
     SetDefaultIQSkills((u8*)&pokemon.IQSkills, FALSE);
     pokemon.speciesNum = species;
     pokemon.heldItem.id = ITEM_NOTHING;
     pokemon.heldItem.quantity = 0;
     pokemon.unk1C = 0;
     pokemon.unk24 = 0;
     pokemon.dungeonLocation.floor = 0;
     sub_808E490(pokemon.moves, species);

     if (name == NULL) {
         CopyMonsterNametoBuffer(name_buffer, species);
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
         temp = &gRecruitedPokemonRef->pokemon[i];
         if (!((u8)gRecruitedPokemonRef->pokemon[i].unk0 & 1)) {
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
