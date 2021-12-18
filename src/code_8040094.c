#include "global.h"
#include "play_time.h"
#include "file_system.h"
#include "dungeon_global_data.h"

extern s32 gUnknown_80F6568[];
extern u8 gUnknown_202EE01;
extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gDungeonFileArchive;
extern struct OpenedFile *gUnknown_202EE04;

extern void sub_803F7BC(void);
extern void sub_80060EC(void);
extern void sub_800CB20(void);
extern void LoadBufferedInputs(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_8083F58(void);
extern void sub_8011860(void);

extern void sub_803F580(u32);
extern void sub_8049ED4();
extern void sub_8040A84();
extern void SendMessage(u32, const char *);

extern const char *gUnknown_80FD040; // It became brighter on the floor

extern struct MapTile *GetMapEntity(u32, u32);

// Luminous Orb???
void HandleLuminousOrbAction(u32 param_1)
{
  struct MapTile *mapTile;
  int XCoord;
  int YCoord;

  gDungeonGlobalData->unk1820B = 1;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      mapTile = GetMapEntity(XCoord, YCoord);
      mapTile->unk4 = mapTile->unk4 | 1;
    }
  }
  sub_803F580(0);
  sub_8049ED4();
  sub_8040A84();
  SendMessage(param_1, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeonGlobalData->unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    sub_8083F58();
    sub_8011860();
}

void sub_80400D4(void)
{
    s32 temp;
    temp = gDungeonGlobalData->unk18200;
    if(temp == 0)
        return;
    if(temp > 0x1E)
        temp = 0x1F;
    gDungeonGlobalData->unk181FC = gUnknown_80F6568[temp];
    gDungeonGlobalData->unk18200--;
    if(gDungeonGlobalData->unk18200 == 0)
        gDungeonGlobalData->unk18200 = gDungeonGlobalData->unk18204;
}

void sub_8040124(void)
{
    gUnknown_202EE01 = 0;
}

void sub_8040130(void)
{
    gUnknown_202EE04 = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gDungeonFileArchive);
}
