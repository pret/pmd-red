#include "global.h"
#include "code_800558C.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "def_filearchives.h"
#include "dungeon_message.h"
#include "structs/dungeon_entity.h"
#include "structs/str_dungeon.h"
#include "dungeon_map_access.h"
#include "dungeon_music.h"
#include "file_system.h"
#include "play_time.h"

extern s32 gUnknown_80F6568[];
extern const char gUnknown_80F6604; // "zmappat"

extern void sub_803F7BC(void);

extern void sub_803F580(u32);
extern void ShowWholeRevealedDungeonMap();

extern const char *gUnknown_80FD040; // It became brighter on the floor

// Luminous Orb???
void HandleLuminousOrbAction(Entity *pokemon)
{
  int XCoord;
  int YCoord;

  gDungeon->unk181e8.allTilesRevealed = TRUE;

  for(YCoord = 0; YCoord < DUNGEON_MAX_SIZE_Y; YCoord++)
  {
    for(XCoord = 0; XCoord < DUNGEON_MAX_SIZE_X; XCoord++)
    {
      Tile *mapTile = GetTileMut(XCoord, YCoord);
      mapTile->spawnOrVisibilityFlags |= VISIBILITY_FLAG_REVEALED;
    }
  }
  sub_803F580(0);
  sub_8049ED4();
  ShowWholeRevealedDungeonMap();
  LogMessageByIdWithPopupCheckUser(pokemon, gUnknown_80FD040);
}

void sub_8040094(u8 r0)
{
    gDungeon->unk181e8.unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    WaitForNextFrameAndAdvanceRNG();
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
