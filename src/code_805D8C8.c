#include "global.h"
#include "file_system.h"
#include "dungeon_global_data.h"
#include "dungeon_util.h"

extern struct FileArchive gMonsterFileArchive;
extern u8 gUnknown_8106EA0[]; // ax%03d 
extern int sprintf(char *, const char *, ...);
void sub_8068838(s16, bool32);
void sub_80688B0(void);
void sub_8068884(void);

void sub_8068768(void)
{
    struct Entity *entity;
    int index;

    for(index = 0; index < DUNGEON_MAX_POKEMON; index++)
    {
        entity = gDungeon->allPokemon[index];
        if ((entity != NULL) && EntityExists(entity)) {
            sub_8068838(entity->info->apparentID, FALSE);
        }
    }
}

void sub_80687AC(void)
{
    gDungeon->unk37F0 = 0x400;
    gDungeon->unk37F4 = 0xA;
}

struct OpenedFile *sub_80687D0(s16 _id)
{
    s32 id = _id;
    return gDungeon->sprites[id];
}

// 85.94 matching (Seth)
// https://decomp.me/scratch/CI98Y 
//
#ifdef NONMATCING
void sub_80687EC(s32 _id)
{
  u8 name [12];
  s16 id = _id;

  if (gDungeon->sprites[id] == NULL) {
    sprintf(name,gUnknown_8106EA0);
    gDungeon->sprites[id] = OpenFileAndGetFileDataPtr(name,&gMonsterFileArchive);
  }
}
#else
NAKED
void sub_80687EC(s32 _id)
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

void sub_8068838(s16 id, bool32 _param_2)
{
    s32 id_s32 = id;
    bool8 param_2 = _param_2;


    if ((param_2 == 0) &&
        ((id_s32 == MONSTER_DEOXYS_NORMAL) || (id_s32 == MONSTER_DEOXYS_ATTACK) || (id_s32 == MONSTER_DEOXYS_DEFENSE) || (id_s32 == MONSTER_DEOXYS_SPEED))) {
        sub_80688B0();
    }
    else {
        sub_80687EC(id_s32);
        if ((u16)(id_s32 - MONSTER_CASTFORM) < 4) {
            sub_8068884();
        }
    }
}

void sub_8068884(void)
{
    sub_80687EC(MONSTER_CASTFORM);
    sub_80687EC(MONSTER_CASTFORM_SNOWY);
    sub_80687EC(MONSTER_CASTFORM_SUNNY);
    sub_80687EC(MONSTER_CASTFORM_RAINY);
}

void sub_80688B0(void)
{
    sub_80687EC(gDungeon->unk3800);
}

void CloseAllSpriteFiles(void)
{
    s32 index;

    for(index = 0; index < 0x1A8; index++)
    {
        if (gDungeon->sprites[index] != NULL) {
            CloseFile(gDungeon->sprites[index]);
            gDungeon->sprites[index] = NULL;
        }
    } 
}


