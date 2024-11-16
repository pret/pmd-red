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
  Tile *mapTile;
  int XCoord;
  int YCoord;

  gDungeon->unk181e8.unk1820B = 1;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      mapTile = GetTileMut(XCoord, YCoord);
      mapTile->unk4 = mapTile->unk4 | 1;
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
