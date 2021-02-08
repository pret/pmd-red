#include "global.h"
#include "pokemon.h"
#include "file_system.h"

extern int sprintf(char *, const char *, ...);

extern struct gPokemon *gMonsterParameters;
extern struct FileArchive gMonsterFileArchive;
extern const char gUnknown_8107684[];

u8 *GetCategoryString(s16 index)
{
    return gMonsterParameters[index].category;
}

u8 GetPokemonSize(s16 index)
{
    return gMonsterParameters[index].size;
}

u8 GetShadowSize(s16 index)
{
    return gMonsterParameters[index].shadow_size;
}

s32 GetMoveSpeed(s16 index)
{
    return gMonsterParameters[index].move_speed;
}

u8 GetWalkableTiles(s16 index)
{
    return gMonsterParameters[index].walkable_tiles;
}

u8 GetUnk1B(s16 index)
{
    return ((u8)(gMonsterParameters[index].unk1B) << 25) >> 24;
}

bool8 GetIsMoving(s16 index)
{
    return gMonsterParameters[index].isMoving;
}

u8 GetUnk1D(s16 index)
{
    return gMonsterParameters[index].unk1D;
}

u16 GetLowKickDmg(s16 index)
{
    return gMonsterParameters[index].lowkick_dmg;
}

u16 GetSizeOrbDmg(s16 index)
{
    return gMonsterParameters[index].sizeorb_dmg;
}

u8 GetFriendArea(s16 index)
{
    return gMonsterParameters[index].friend_area;
}

u16 GetBaseHP(s16 index)
{
    return gMonsterParameters[index].base_hp;
}

bool8 GetUnk33(s16 index)
{
    return gMonsterParameters[index].unk33;
}

u8 GetUnk12(s16 index)
{
    return gMonsterParameters[index].unk12;
}

s16 GetPokemonEvolveFrom(s16 index)
{
    return gMonsterParameters[index].pre.evolve_from;
}

u16 GetPokemonAttSpatt(s16 index, u32 r1)
{
    return gMonsterParameters[index].base_att_spatt[r1];
}

u16 GetPokemonDefSpdef(s16 index, u32 r1)
{
    return gMonsterParameters[index].base_def_spdef[r1];
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

s16 sub_808DCA0(s16 index, u32 r1)
{
    return gMonsterParameters[index].unk3C[r1];
}

s16 GetBaseRecruit(s16 index)
{
    return gMonsterParameters[index].base_recruit;
}

s16 sub_808DCDC(s16 index, s32 r1)
{
    return gMonsterParameters[index].unk42[r1];
}


s16 sub_808DCFC(s16 index)
{
    return gMonsterParameters[index].unk3C[1];
}

#ifdef NONMATCHING
u32 CalculateEXPGain(s16 index, s32 level)
{
    return gMonsterParameters[index].base_exp + (gMonsterParameters[index].base_exp * (level- 1)) / 10;
}
#else
NAKED
u32 CalculateEXPGain(s16 index, s32 level)
{
	asm_unified("\tpush {r4,lr}\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tldr r2, _0808DD44\n"
	"\tldr r3, [r2]\n"
	"\tlsls r2, r0, 3\n"
	"\tadds r2, r0\n"
	"\tlsls r2, 3\n"
	"\tadds r2, r3\n"
	"\tldr r4, [r2, 0x20]\n"
	"\tsubs r1, 0x1\n"
	"\tadds r0, r4, 0\n"
	"\tmuls r0, r1\n"
	"\tmovs r1, 0xA\n"
	"\tbl __divsi3\n"
	"\tadds r4, r0\n"
	"\tadds r0, r4, 0\n"
	"\tpop {r4}\n"
	"\tpop {r1}\n"
	"\tbx r1\n"
	"\t.align 2, 0\n"
"_0808DD44: .4byte gMonsterParameters");
}
#endif

s16 sub_808DD48(s16 index, struct unkEvolve *r1)
{
    struct EvolveStruct1 temp2;
    struct EvolveNeeds temp1;
    temp1 = gMonsterParameters[index].need;
    temp2 = gMonsterParameters[index].pre;
    r1->conditions = temp2;
    r1->needs = temp1;
    // The return value is not used anywhere, but necessary for the function to match.
    return index;
}

u8 GetPokemonOverworldPalette(s16 index, u32 r1)
{
    // Had to have this cast to match
    u32 temp;
    temp = index;
    if (r1 != 0)
    {
        return 10;
    }
    else 
    {
        return gMonsterParameters[temp].overworld_palette;
    }
}

struct OpenedFile *OpenPokemonDialogueSpriteFile(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[index].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, index); // "kao%03d"
    return OpenFile(buffer, &gMonsterFileArchive);
}

struct OpenedFile *GetDialogueSpriteDataPtr(s16 index)
{
    // Looks like this loads the dialogue sprite for the pokemon

    char buffer[0xC];
    if(gMonsterParameters[index].dialogue_sprites == 0)
    {
        return NULL;
    }
    sprintf(buffer, gUnknown_8107684, index); // "kao%03d"
    return OpenFileAndGetFileDataPtr(buffer, &gMonsterFileArchive);
}

bool8 IsPokemonDialogueSpriteAvail(s16 index, s32 r1)
{
    // checking to see if dialogue sprite is available??
    return (gMonsterParameters[index].dialogue_sprites >> r1) & 1;
}
