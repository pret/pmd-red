#include "global.h"
#include "code_800558C.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "dungeon_message.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "file_system.h"
#include "play_time.h"
#include "cpu.h"
#include "dungeon.h"

extern s32 gUnknown_80F6568[];
extern u8 gUnknown_202EE01;
extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gDungeonFileArchive;
extern OpenedFile *gUnknown_202EE04;

extern void sub_803F7BC(void);

extern void sub_803F580(u32);
extern void sub_8040A84();

extern const char *gUnknown_80FD040; // It became brighter on the floor

// Luminous Orb???
void HandleLuminousOrbAction(Entity *pokemon)
{
  int XCoord;
  int YCoord;

  gDungeon->unk181e8.unk1820B = 1;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      Tile *mapTile = GetTileMut(XCoord, YCoord);
      mapTile->spawnOrVisibilityFlags |= 1;
    }
  }
  sub_803F580(0);
  sub_8049ED4();
  sub_8040A84();
  LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeon->unk181e8.unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    UpdateDungeonMusic();
    sub_8011860();
}

void sub_80400D4(void)
{
    s32 temp;
    temp = gDungeon->unk181e8.unk18200;
    if(temp == 0)
        return;
    if(temp > 0x1E)
        temp = 0x1F;
    gDungeon->unk181e8.unk181FC = gUnknown_80F6568[temp];
    gDungeon->unk181e8.unk18200--;
    if(gDungeon->unk181e8.unk18200 == 0)
        gDungeon->unk181e8.unk18200 = gDungeon->unk181e8.unk18204;
}

void sub_8040124(void)
{
    gUnknown_202EE01 = 0;
}

void sub_8040130(void)
{
    gUnknown_202EE04 = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gDungeonFileArchive);
}

extern DungeonPos gUnknown_203B410;
extern u8 gUnknown_202EE00;
extern void *gUnknown_202EE08;

void sub_8040238(void);

void sub_8040150(bool8 a0)
{
    s32 i, j;

    for (i = 0; i < UNK1822C_ARR_COUNT; i++) {
        for (j = 0; j < UNK1822C_ARR_COUNT_2; j++) {
            CpuClear(&gDungeon->unk1822C.unk1822C[i][j], sizeof(struct UnkDungeonGlobal_1822C_Sub));
            gDungeon->unk1822C.unk1BA2C[i][j] = 0;
        }
    }

    if (!a0) {
        gUnknown_203B410.x = 100;
        gUnknown_203B410.y = 100;
    }

    gDungeon->unk1822C.unk1BDCC = 0;
    gDungeon->unk1822C.unk1BDD0 = 1;
    gDungeon->unk1822C.unk1BDD2 = 0;
    gUnknown_202EE00 = 1;
    gUnknown_202EE08 = (void *) VRAM + 0x1700;
    gUnknown_202EE01 = 1;
    sub_8040238();
}
