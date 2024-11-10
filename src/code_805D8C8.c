#include "global.h"
#include "code_805D8C8.h"
#include "structs/str_dungeon.h"
#include "dungeon_util.h"
#include "pokemon.h"

// monster_sbin.s
extern const struct FileArchive gMonsterFileArchive;
// data_8106A4C.s
extern const u8 gUnknown_8106EA0[]; // ax%03d

// ???
extern s32 sprintf(char *, const char *, ...);

static void EnsureCastformLoaded(void);
static void EnsureDeoxysLoaded(void);

void sub_8068768(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (entity != NULL && EntityExists(entity))
            LoadPokemonSprite(GetEntInfo(entity)->apparentID, FALSE);
    }
}

void sub_80687AC(void)
{
    gDungeon->unk37F0 = 0x400;
    gDungeon->unk37F4 = 10;
}

OpenedFile *GetSpriteData(s16 species)
{
    s32 species32 = SpeciesId(species);
    return gDungeon->sprites[species32];
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