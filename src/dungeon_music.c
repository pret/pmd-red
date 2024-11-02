#include "global.h"
#include "code_80118A4.h"
#include "constants/bg_music.h"
#include "dungeon.h"
#include "music.h"
#include "structs/menu.h"
#include "structs/str_dungeon.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "text_util.h"


extern MenuInputStruct gUnknown_202EE10;

extern u8 *gUnknown_80FE6F4[];
extern u8 gUnknown_810AC60; // 0xC
extern u8 gUnknown_810AC62; // 0xC
extern u8 gUnknown_810AC68; // 0x8
extern u8 gUnknown_810AC64; // 0x8
extern u8 gUnknown_810AC66; // 0x8

extern void sub_80709C8(u8 *buffer, EntityInfo *entityInfo);

// Dungeon Music Player adds in this flag to tell
// the system to fade in rather than immediately playing
#define DUNGEON_MUSIC_FADE_IN 0x8000

void sub_8083AB0(s16 param_0, Entity * target, Entity * entity)
{
  u8 *defPtr;
  u8 *attackPtr;
  u8 *spDefPtr;
  EntityInfo * entityInfo;
  EntityInfo * targetEntityInfo;
  u8 *spAttPtr;
  u8 buffer [0x14];
  UnkDungeonGlobal_unk1CE98_sub *temp;
  u8 *id;
  s32 param_0_s32 = param_0;

  temp = &gDungeon->unk1CE98;
  targetEntityInfo = NULL;
  if ((EntityExists(target)) && (GetEntityType(target) == ENTITY_MONSTER)) {
    targetEntityInfo = GetEntInfo(target);
  }
  entityInfo = GetEntInfo(entity);
  if (targetEntityInfo != NULL) {
    sub_80709C8(buffer, targetEntityInfo);
    CopyStringtoBuffer(temp->buffer1, buffer);
  }
  else {
    CopyStringtoBuffer(temp->buffer1, *gUnknown_80FE6F4); // Someone
  }
  sub_80709C8(buffer,entityInfo);
  CopyStringtoBuffer(temp->buffer2, buffer);
  temp->moveID = param_0_s32;
  temp->heldItem = entityInfo->heldItem;
  temp->exp = entityInfo->exp;
  temp->level = entityInfo->level;
  temp->maxHPStat = entityInfo->maxHPStat;
  temp->atk = entityInfo->atk[0];
  temp->spAtk = entityInfo->atk[1];
  temp->def = entityInfo->def[0];
  temp->spDef = entityInfo->def[1];
  temp->dungeonLocation = gDungeon->dungeonLocation;
  attackPtr = &temp->attBoost;
  *attackPtr = 0;
  spAttPtr = &temp->spAttBoost;
  *spAttPtr = 0;
  defPtr = &temp->defBoost;
  *defPtr = 0;
  spDefPtr = &temp->spDefBoost;
  *spDefPtr = 0;
  if ((entityInfo->heldItem.flags & ITEM_FLAG_EXISTS) && !(entityInfo->heldItem.flags & ITEM_FLAG_STICKY)) {
    id = &entityInfo->heldItem.id;
    if (*id == ITEM_POWER_BAND) {
      *attackPtr += gUnknown_810AC60;
    }
    if (*id == ITEM_MUNCH_BELT) {
      *attackPtr += gUnknown_810AC68;
    }
    if (*id == ITEM_SPECIAL_BAND) {
      *spAttPtr += gUnknown_810AC62;
    }
    if (*id == ITEM_MUNCH_BELT) {
      *spAttPtr += gUnknown_810AC68;
    }
    if (*id == ITEM_DEF_SCARF) {
      *defPtr += gUnknown_810AC64;
    }
    if (*id == ITEM_ZINC_BAND) {
      *spDefPtr += gUnknown_810AC66;
    }
  }
}

bool8 sub_8083C24(void)
{
  UnkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if (temp->moveID < 0x226) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8083C50(void)
{
  UnkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if ((temp->moveID == 0x227) || (temp->moveID == 0x22A) || (temp->moveID == 0x228)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8083C88(u8 param_1)
{
  UnkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if ((!HasCheckpoint(gDungeon->dungeonLocation.id) &&
      ((gDungeon->unk65C != 0) || (param_1 != 0))) ||
     (temp->moveID != 0x227)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void sub_8083CE0(u8 param_1)
{
  if ((param_1 == 0) || (1 < gUnknown_202EE10.unk1A)) {
    PlayFanfareSE(0x12d,MAX_VOLUME);
  }
}

void sub_8083D08(void)
{
    PlayFanfareSE(0x12E, MAX_VOLUME);
}

void sub_8083D1C(void)
{
    PlayFanfareSE(0x133, MAX_VOLUME);
}

void sub_8083D30(void)
{
    PlayFanfareSE(0x12F, MAX_VOLUME);
}

void sub_8083D44(void)
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
  gDungeon->unk66F = 0;
  gDungeon->monsterHouseTriggeredEvent = FALSE;
  gDungeon->unk699 = 0;
  gDungeon->bossSongIndex = STOP_BGM;
}

void PlayDungeonCompleteBGM(void)
{
  DungeonStartNewBGM(MUS_DUNGEON_COMPLETE);
  gDungeon->unk66F = 0;
  gDungeon->monsterHouseTriggeredEvent = FALSE;
  gDungeon->unk699 = 0;
  gDungeon->bossSongIndex = STOP_BGM;
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
    xxx_call_stop_bgm();
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
#ifndef NONMATCHING
  register s32 currSongIndex asm("r1");
  register u16 *bossSongIndex asm("r3");
#else
  s32 currSongIndex;
  u16 *bossSongIndex;
#endif
  s32 newSongIndex;
  DungeonMusicPlayer *musPlayer;

  musPlayer = &gDungeon->musPlayer;

  bossSongIndex = &gDungeon->bossSongIndex;
  newSongIndex = *bossSongIndex;
  if (newSongIndex == STOP_BGM) {
    if (gDungeon->unk66F != 0) {
        newSongIndex = MUS_STOP_THIEF;
    }
    else if (gDungeon->monsterHouseTriggeredEvent) {
        newSongIndex = MUS_MONSTER_HOUSE;
      }
    else if (gDungeon->unk699 != 0) {
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
        currSongIndex = musPlayer->songIndex;
        if (currSongIndex == STOP_BGM) {
            musPlayer->state = 0;
        }
        else {
            if ((currSongIndex & DUNGEON_MUSIC_FADE_IN)) {
                StartNewBGM(currSongIndex & ~(DUNGEON_MUSIC_FADE_IN));
            }
            else {
                FadeInNewBGM(currSongIndex & ~(DUNGEON_MUSIC_FADE_IN), musPlayer->fadeInSpeed);
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
