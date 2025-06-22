#include "global.h"
#include "globaldata.h"
#include "constants/bg_music.h"
#include "structs/menu.h"
#include "music_util.h"
#include "dungeon_info.h"
#include "dungeon_music.h"
#include "music.h"
#include "run_dungeon.h"

extern MenuInputStruct gDungeonMenu;

// Dungeon Music Player adds in this flag to tell
// the system to fade in rather than immediately playing
#define DUNGEON_MUSIC_FADE_IN 0x8000

void PlayDungeonCursorSE(bool8 checkMenuEntriesCount)
{
    if (!checkMenuEntriesCount || gDungeonMenu.currPageEntries > 1)
        PlayFanfareSE(0x12d,MAX_VOLUME);
}

void PlayDungeonConfirmationSE(void)
{
    PlayFanfareSE(0x12E, MAX_VOLUME);
}

void sub_8083D1C(void)
{
    PlayFanfareSE(0x133, MAX_VOLUME);
}

void PlayDungeonCancelSE(void)
{
    PlayFanfareSE(0x12F, MAX_VOLUME);
}

void PlayDungeonStartButtonSE(void)
{
    PlayFanfareSE(0x130, MAX_VOLUME);
}

void sub_8083D58(void)
{
    PlayFanfareSE(0xC8, MAX_VOLUME);
}

void sub_8083D68(void)
{
    PlayFanfareSE(0xCF, MAX_VOLUME);
}

void sub_8083D78(void)
{
    PlayFanfareSE(0xD3, MAX_VOLUME);
}

void sub_8083D88(void)
{
    PlayFanfareSE(0xCC, MAX_VOLUME);
}

void PlayDungeonFailBGM(void)
{
  DungeonStartNewBGM(MUS_DUNGEON_FAIL);
  gDungeon->unk644.unk2B = 0;
  gDungeon->unk644.monsterHouseTriggeredEvent = FALSE;
  gDungeon->unk644.unk55 = 0;
  gDungeon->unk644.bossSongIndex = STOP_BGM;
}

void PlayDungeonCompleteBGM(void)
{
  DungeonStartNewBGM(MUS_DUNGEON_COMPLETE);
  gDungeon->unk644.unk2B = 0;
  gDungeon->unk644.monsterHouseTriggeredEvent = FALSE;
  gDungeon->unk644.unk55 = 0;
  gDungeon->unk644.bossSongIndex = STOP_BGM;
}

void sub_8083E28(void)
{
    PlayFanfareSE(0xCF, MAX_VOLUME);
}

void PlaySoundEffect(u32 songIndex)
{
    u16 songIndex_u32 = songIndex;
    if(songIndex_u32 != STOP_SOUND_EFFECT)
        PlayFanfareSE(songIndex_u32, MAX_VOLUME);
}

void StopSoundEffect(u32 songIndex)
{
    u16 songIndex_u32 = songIndex;
    if(songIndex_u32 != STOP_SOUND_EFFECT)
        StopFanfareSE(songIndex_u32);
}

bool8 IsFanfareSEPlaying_2(u16 songIndex)
{
    return IsFanfareSEPlaying(songIndex);
}

void DungeonStartNewBGM(u16 songIndex)
{
  gDungeon->musPlayer.queuedSongIndex = songIndex;
  gDungeon->musPlayer.fadeInSpeed = 0;
}

void DungeonFadeInNewBGM(u16 songIndex, u32 fadeInSpeed)
{
  gDungeon->musPlayer.queuedSongIndex = DUNGEON_MUSIC_FADE_IN | songIndex;
  gDungeon->musPlayer.fadeInSpeed = fadeInSpeed;
}

void DungeonFadeOutBGM(u16 speed)
{
  FadeOutAllMusic(speed);
  gDungeon->musPlayer.songIndex = STOP_BGM;
  gDungeon->musPlayer.pastSongIndex = STOP_BGM;
  gDungeon->musPlayer.queuedSongIndex = STOP_BGM;
}

void DungeonStopBGM(void)
{
    StopDungeonBGM();
    StopBGMusic();
}

u16 DungeonGetCurrentBGSong(void)
{
    return GetCurrentBGSong();
}

void StopDungeonBGM(void)
{
  DungeonMusicPlayer *temp = &gDungeon->musPlayer;
  temp->state = 0;
  temp->fadeOutSpeed = 0;
  temp->songIndex = STOP_BGM;
  temp->pastSongIndex = STOP_BGM;
  temp->queuedSongIndex = STOP_BGM;
}

void UpdateDungeonMusic(void)
{
  s32 newSongIndex;
  DungeonMusicPlayer *musPlayer = &gDungeon->musPlayer;

  if (gDungeon->unk644.bossSongIndex != STOP_BGM) {
      newSongIndex = gDungeon->unk644.bossSongIndex;
  }
  else {
      if (gDungeon->unk644.unk2B != 0) {
        newSongIndex = MUS_STOP_THIEF;
    }
    else if (gDungeon->unk644.monsterHouseTriggeredEvent) {
        newSongIndex = MUS_MONSTER_HOUSE;
      }
    else if (gDungeon->unk644.unk55 != 0) {
        newSongIndex = MUS_KECLEON_SHOP;
    }
    else {
        newSongIndex = musPlayer->queuedSongIndex;
    }
  }

  if (musPlayer->state == 4) {
    if (newSongIndex != musPlayer->pastSongIndex) {
      musPlayer->state = 2;
      musPlayer->songIndex = newSongIndex;
    }
  }
  else if ((newSongIndex != STOP_BGM) && (musPlayer->songIndex == STOP_BGM)) {
      musPlayer->state = 1;
      musPlayer->songIndex = newSongIndex;
  }

  switch(musPlayer->state) {
    case 0:
    case 4:
    default:
        break;
    case 1:
        if (musPlayer->songIndex == STOP_BGM) {
            musPlayer->state = 0;
        }
        else {
            if ((musPlayer->songIndex & DUNGEON_MUSIC_FADE_IN)) {
                StartNewBGM(musPlayer->songIndex & ~(DUNGEON_MUSIC_FADE_IN));
            }
            else {
                FadeInNewBGM(musPlayer->songIndex & ~(DUNGEON_MUSIC_FADE_IN), musPlayer->fadeInSpeed);
            }
            musPlayer->pastSongIndex = musPlayer->songIndex;
            musPlayer->state = 4;
        }
        musPlayer->songIndex = STOP_BGM;
        break;
    case 2:
        FadeOutBGM(0x1e);
        musPlayer->fadeOutSpeed = 0x1e;
        musPlayer->state = 3;
        break;
    case 3:
        if ((musPlayer->fadeOutSpeed != 0) && (musPlayer->fadeOutSpeed--, musPlayer->fadeOutSpeed != 0)) {
            break;
        }

        if (musPlayer->songIndex == STOP_BGM) {
            StopBGM();
            musPlayer->state = 0;
        }
        else {
            musPlayer->state = 1;
        }
  }
}
