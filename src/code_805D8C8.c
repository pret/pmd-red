#include "global.h"
#include "code_805D8C8.h"
#include "structs/str_dungeon.h"
#include "dungeon_util.h"

// monster_sbin.s
extern const struct FileArchive gMonsterFileArchive;
// data_8106A4C.s
extern const u8 gUnknown_8106EA0[]; // ax%03d

// ???
extern s32 sprintf(char *, const char *, ...);

static void sub_8068884(void);
static void sub_80688B0(void);

void sub_8068768(void)
{
    Entity *entity;
    s32 i;

    for (i = 0; i < DUNGEON_MAX_POKEMON; i++) {
        entity = gDungeon->allPokemon[i];

        if (entity != NULL && EntityExists(entity))
            sub_8068838(entity->info->apparentID, FALSE);
    }
}

void sub_80687AC(void)
{
    gDungeon->unk37F0 = 0x400;
    gDungeon->unk37F4 = 10;
}

OpenedFile *sub_80687D0(s16 species)
{
    s32 species32 = species;
    return gDungeon->sprites[species32];
}

// 85.94 matching (Seth)
// https://decomp.me/scratch/CI98Y
//
#ifdef NONMATCHING
static void sub_80687EC(s32 _id)
{
    u8 name [12];
    s16 id = _id;

    if (gDungeon->sprites[id] == NULL) {
        sprintf(name, gUnknown_8106EA0);
        gDungeon->sprites[id] = OpenFileAndGetFileDataPtr(name, &gMonsterFileArchive);
    }
}
#else
NAKED
static void sub_80687EC(s32 _id)
{
    asm_unified(
    "\tpush {r4,r5,lr}\n"
    "\tsub sp, 0xC\n"
    "\tlsls r0, 16\n"
    "\tasrs r2, r0, 16\n"
    "\tldr r5, _08068828\n"
    "\tldr r0, [r5]\n"
    "\tlsls r4, r2, 2\n"
    "\tldr r1, _0806882C\n"
    "\tadds r0, r1\n"
    "\tadds r0, r4\n"
    "\tldr r0, [r0]\n"
    "\tcmp r0, 0\n"
    "\tbne _08068820\n"
    "\tldr r1, _08068830\n"
    "\tmov r0, sp\n"
    "\tbl sprintf\n"
    "\tldr r1, _08068834\n"
    "\tmov r0, sp\n"
    "\tbl OpenFileAndGetFileDataPtr\n"
    "\tldr r1, [r5]\n"
    "\tldr r2, _0806882C\n"
    "\tadds r1, r2\n"
    "\tadds r1, r4\n"
    "\tstr r0, [r1]\n"
"_08068820:\n"
    "\tadd sp, 0xC\n"
    "\tpop {r4,r5}\n"
    "\tpop {r0}\n"
    "\tbx r0\n"
    "\t.align 2, 0\n"
"_08068828: .4byte gDungeon\n"
"_0806882C: .4byte 0x00017b44\n"
"_08068830: .4byte gUnknown_8106EA0\n"
"_08068834: .4byte gMonsterFileArchive");
}
#endif

void sub_8068838(s16 id, bool32 a1)
{
    s32 id_s32 = id;
    bool8 param_2 = a1;

    if (!param_2 &&
        (id_s32 == MONSTER_DEOXYS_NORMAL || id_s32 == MONSTER_DEOXYS_ATTACK || id_s32 == MONSTER_DEOXYS_DEFENSE || id_s32 == MONSTER_DEOXYS_SPEED)) {
        sub_80688B0();
    }
    else {
        sub_80687EC(id_s32);
        // >= MONSTER_CASTFORM && <= MONSTER_CASTFORM_RAINY
        if ((u16)(id_s32 - MONSTER_CASTFORM) < 4)
            sub_8068884();
    }
}

static void sub_8068884(void)
{
    sub_80687EC(MONSTER_CASTFORM);
    sub_80687EC(MONSTER_CASTFORM_SNOWY);
    sub_80687EC(MONSTER_CASTFORM_SUNNY);
    sub_80687EC(MONSTER_CASTFORM_RAINY);
}

static void sub_80688B0(void)
{
    sub_80687EC(gDungeon->unk3800);
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