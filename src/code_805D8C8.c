#include "global.h"
#include "code_805D8C8.h"
#include "structs/str_dungeon.h"
#include "dungeon_util.h"
#include "dungeon_util_1.h"
#include "file_system.h"
#include "pokemon.h"
#include "pokemon_3.h"

// monster_sbin.s
extern const struct FileArchive gMonsterFileArchive;
// data_8106A4C.s
extern const u8 gUnknown_8106EA0[]; // ax%03d
extern const u8 gUnknown_8106E98[]; // palet
// ???
extern s32 sprintf(char *, const char *, ...);

static void EnsureCastformLoaded(void);
static void EnsureDeoxysLoaded(void);

void OpenDungeonPaletteFile(void)
{
    gDungeon->paletFile = OpenFileAndGetFileDataPtr(gUnknown_8106E98, &gMonsterFileArchive);
}

void CloseDungeonPaletteFile(void)
{
    CloseFile(gDungeon->paletFile);
}

void LoadDungeonPokemonSprites(void)
{
    s32 index;

    for(index = 0; index < 0x1A8; index++)
    {
        gDungeon->sprites[index] = NULL;
    }
    LoadPokemonSprite(MONSTER_DECOY, TRUE);
    for(index = 0; index < gDungeon->unk37E4; index++)
    {
        LoadPokemonSprite(ExtractSpeciesIndex(&gDungeon->unk343C[index]), TRUE);
    }
    if(gDungeon->unk644.unk44)
    {
        LoadPokemonSprite(gDungeon->unk644.unk44, TRUE);
    }
    for(index = 0; index < 4; index++)
    {
        PokemonStruct2 *ptr = &gRecruitedPokemonRef->pokemon2[index];
        if(PokemonFlag1Struct2(ptr))
            if(PokemonFlag2Struct2(ptr))
                LoadPokemonSprite(ptr->speciesNum, FALSE);
    }
    if(gDungeon->fixedRoomNumber == 0x31)
    {
        for(index = 0; index < MAX_TEAM_MEMBERS; index++)
        {
            PokemonStruct1 *ptr = &gRecruitedPokemonRef->team[index];
            if(PokemonFlag1(ptr))
                LoadPokemonSprite(ptr->speciesNum, TRUE);
        }
    }
}

void sub_8068768(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->activePokemon[i];

        if (entity != NULL && EntityIsValid(entity))
            LoadPokemonSprite(GetEntInfo(entity)->apparentID, FALSE);
    }
}

void sub_80687AC(void)
{
    gDungeon->unk37F0 = 0x400;
    gDungeon->unk37F4 = 10;
}

OpenedFile *GetSpriteData(s32 _species)
{
    s32 species = (s16)(_species);
    return gDungeon->sprites[species];
}

static void EnsureSpriteLoaded(s32 _id) // TODO: Should this param be s16? If so, the castform part of LoadPokemonSprite is preventing us
{
    u8 name[12];
    s32 id = SpeciesId(_id);

    if (gDungeon->sprites[id] == NULL) {
        sprintf(name, gUnknown_8106EA0, id);
        gDungeon->sprites[id] = OpenFileAndGetFileDataPtr(name, &gMonsterFileArchive);
    }
}

void LoadPokemonSprite(s16 id, bool32 a1)
{
    s32 id_s32 = SpeciesId(id);
    bool8 param_2 = a1;

    if (!param_2 && (id_s32 == MONSTER_DEOXYS_NORMAL || id_s32 == MONSTER_DEOXYS_ATTACK || id_s32 == MONSTER_DEOXYS_DEFENSE || id_s32 == MONSTER_DEOXYS_SPEED)) {
        EnsureDeoxysLoaded();
    }
    else {
        EnsureSpriteLoaded(id_s32);

        if ((u16)(id_s32 - MONSTER_CASTFORM) < 4)
            EnsureCastformLoaded();
    }
}
/*void LoadPokemonSprite(s16 id, bool8 a1)
{
    s32 id_s32 = SpeciesId(id);

    if (!a1 && (id_s32 == MONSTER_DEOXYS_NORMAL || id_s32 == MONSTER_DEOXYS_ATTACK || id_s32 == MONSTER_DEOXYS_DEFENSE || id_s32 == MONSTER_DEOXYS_SPEED)) {
        EnsureDeoxysLoaded();
    }
    else {
        EnsureSpriteLoaded(id);

        // TODO: >= MONSTER_CASTFORM && <= MONSTER_CASTFORM_RAINY
        if (id_s32 == MONSTER_CASTFORM || id_s32 == MONSTER_CASTFORM_SNOWY || id_s32 == MONSTER_CASTFORM_SUNNY || id_s32 == MONSTER_CASTFORM_RAINY)
        //if ((u16)(id_s32 - MONSTER_CASTFORM) < 4)
            EnsureCastformLoaded();
    }
}*/

static void EnsureCastformLoaded(void)
{
    EnsureSpriteLoaded(MONSTER_CASTFORM);
    EnsureSpriteLoaded(MONSTER_CASTFORM_SNOWY);
    EnsureSpriteLoaded(MONSTER_CASTFORM_SUNNY);
    EnsureSpriteLoaded(MONSTER_CASTFORM_RAINY);
}

static void EnsureDeoxysLoaded(void)
{
    EnsureSpriteLoaded(gDungeon->deoxysForm);
}

void CloseAllSpriteFiles(void)
{
    s32 i;

    for (i = 0; i < MONSTER_MAX; i++) {
        if (gDungeon->sprites[i] != NULL) {
            CloseFile(gDungeon->sprites[i]);
            gDungeon->sprites[i] = NULL;
        }
    }
}
