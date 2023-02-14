#include "global.h"
#include "constants/bg_music.h"
#include "dungeon.h"
#include "music.h"
#include "dungeon_global_data.h"
#include "dungeon_music.h"
#include "dungeon_util.h"
#include "text_util.h"


struct unkStruct_202EE10
{
    u8 fill0[0x1A];
    s16 unk1A;
};

extern struct unkStruct_202EE10 gUnknown_202EE10;

extern u32 gUnknown_203B458;
extern u8 *gUnknown_80FE6F4[];
extern u8 gUnknown_810AC60; // 0xC
extern u8 gUnknown_810AC62; // 0xC
extern u8 gUnknown_810AC68; // 0x8
extern u8 gUnknown_810AC64; // 0x8
extern u8 gUnknown_810AC66; // 0x8

extern void sub_80709C8(u8 *buffer, struct EntityInfo *entityInfo);
void FadeOutAllMusic(u16);
void xxx_call_stop_bgm(void);

void sub_8083AB0(s16 param_0, struct Entity * target, struct Entity * entity)
{
  u8 *defPtr;
  u8 *attackPtr;
  u8 *spDefPtr;
  struct EntityInfo * entityInfo;
  struct EntityInfo * targetEntityInfo;
  u8 *spAttPtr;
  u8 buffer [0x14];
  struct unkDungeonGlobal_unk1CE98_sub *temp;
  u8 *id;
  s32 param_0_s32 = param_0;

  temp = &gDungeon->unk1CE98;
  targetEntityInfo = NULL;
  if ((EntityExists(target)) && (GetEntityType(target) == ENTITY_MONSTER)) {
    targetEntityInfo = target->info;
  }
  entityInfo = entity->info;
  if (targetEntityInfo != NULL) {
    sub_80709C8(buffer, targetEntityInfo);
    CopyStringtoBuffer(temp->buffer1, buffer);
  }
  else {
    CopyStringtoBuffer(temp->buffer1, *gUnknown_80FE6F4); // Someone
  }
  sub_80709C8(buffer,entityInfo);
  CopyStringtoBuffer(temp->buffer2, buffer);
  temp->unk14 = param_0_s32;
  temp->heldItem = entityInfo->heldItem;
  temp->exp = entityInfo->exp;
  temp->level = entityInfo->level;
  temp->maxHPStat = entityInfo->maxHPStat;
  temp->atk = entityInfo->atk;
  temp->spAtk = entityInfo->spAtk;
  temp->def = entityInfo->def;
  temp->spDef = entityInfo->spDef;
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
  struct unkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if (temp->unk14 < 0x226) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8083C50(void)
{
  struct unkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if ((temp->unk14 == 0x227) || (temp->unk14 == 0x22A) || (temp->unk14 == 0x228)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

bool8 sub_8083C88(u8 param_1)
{
  struct unkDungeonGlobal_unk1CE98_sub *temp;

  temp = &gDungeon->unk1CE98;

  if ((!HasCheckpoint(gDungeon->dungeonLocation.id) && 
      ((gDungeon->unk65C != 0) || (param_1 != 0))) ||
     (temp->unk14 != 0x227)) {
    return TRUE;
  }
  else {
    return FALSE;
  }
}

void sub_8083CE0(u8 param_1)
{
  if ((param_1 == 0) || (1 < gUnknown_202EE10.unk1A)) {
    PlayFanfareSE(0x12d,0x100);
  }
}

void sub_8083D08(void)
{
    PlayFanfareSE(0x12E, 0x100);
}

void sub_8083D1C(void)
{
    PlayFanfareSE(0x133, 0x100);
}

void sub_8083D30(void)
{
    PlayFanfareSE(0x12F, 0x100);
}

void sub_8083D44(void)
{
    PlayFanfareSE(0x130, 0x100);
}

void sub_8083D58(void)
{
    PlayFanfareSE(0xC8, 0x100);
}

void sub_8083D68(void)
{
    PlayFanfareSE(0xCF, 0x100);
}

void sub_8083D78(void)
{
    PlayFanfareSE(0xD3, 0x100);
}

void sub_8083D88(void)
{
    PlayFanfareSE(0xCC, 0x100);
}

void PlayDungeonFailBGM(void)
{
  DungeonStartNewBGM(MUS_DUNGEON_FAIL);
  gDungeon->unk66F = 0;
  gDungeon->unk672 = 0;
  gDungeon->unk699 = 0;
  gDungeon->unk66A = 999;
}

void PlayDungeonCompleteBGM(void)
{
  DungeonStartNewBGM(MUS_DUNGEON_COMPLETE);
  gDungeon->unk66F = 0;
  gDungeon->unk672 = 0;
  gDungeon->unk699 = 0;
  gDungeon->unk66A = 999;
}

void sub_8083E28(void)
{
    PlayFanfareSE(0xCF, 0x100);
}

void PlaySoundEffect(u32 songIndex)
{
    u16 songIndex_u32 = songIndex;
    if(songIndex_u32 != 0x3E5)
        PlayFanfareSE(songIndex_u32, 0x100);
}

void StopSoundEffect(u32 songIndex)
{
    u16 songIndex_u32 = songIndex;
    if(songIndex_u32 != 0x3E5)
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
  gDungeon->musPlayer.queuedSongIndex = 0x80 << 8 | songIndex;
  gDungeon->musPlayer.fadeInSpeed = fadeInSpeed;
}

void DungeonFadeOutBGM(u16 speed)
{
  FadeOutAllMusic(speed);
  gDungeon->musPlayer.songIndex = 999;
  gDungeon->musPlayer.pastSongIndex = 999;
  gDungeon->musPlayer.queuedSongIndex = 999;
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
  struct DungeonMusicPlayer *temp = &gDungeon->musPlayer;
  temp->state = 0;
  temp->fadeOutSpeed = 0;
  temp->songIndex = 999;
  temp->pastSongIndex = 999;
  temp->queuedSongIndex = 999;
}

void UpdateDungeonMusic(void)
{
#ifndef NONMATCHING    
  register s32 uVar1 asm("r1");
  register u16 *uVar3 asm("r3");
#else
  s32 uVar1;
  u16 *uVar3;
#endif
  s32 songIndex1;
  struct DungeonMusicPlayer *musPlayer;
  
  musPlayer = &gDungeon->musPlayer;

  uVar3 = &gDungeon->unk66A;
  songIndex1 = *uVar3;
  if (songIndex1 == 999) {
    if (gDungeon->unk66F != 0) {
        songIndex1 = MUS_STOP_THIEF;
    }
    else if (gDungeon->unk672 != 0) {
        songIndex1 = MUS_MONSTER_HOUSE;
      }
    else if (gDungeon->unk699 != 0) {
        songIndex1 = MUS_KECLEON_SHOP;
    }
    else {
        songIndex1 = musPlayer->queuedSongIndex;
    }
  }
  if (musPlayer->state == 4) {
    if (songIndex1 != musPlayer->pastSongIndex) {
      musPlayer->state = 2;
      musPlayer->songIndex = songIndex1;
    }
  }
  else if ((songIndex1 != 999) && (musPlayer->songIndex == 999)) {
      musPlayer->state = 1;
      musPlayer->songIndex = songIndex1;
  }
  switch(musPlayer->state) {
    case 0:
    case 4:
    default:
        break;
    case 1:
        uVar1 = musPlayer->songIndex;
        if (uVar1 == 999) {
            musPlayer->state = 0;
        }
        else {
            if ((uVar1 & 0x8000) != 0) {
                StartNewBGM(uVar1 & 0x7fff);
            }
            else {
                FadeInNewBGM(uVar1 & 0x7fff, musPlayer->fadeInSpeed);
            }
            musPlayer->pastSongIndex = musPlayer->songIndex;
            musPlayer->state = 4;
        }
        musPlayer->songIndex = 999;
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
        if (musPlayer->songIndex == 999) {
            StopBGM();
            musPlayer->state = 0;
        }
        else {
            musPlayer->state = 1;
        }
  }
}


void sub_808408C(u32 param_1)
{
  gUnknown_203B458 = (1 | param_1) & 0xffffff;
}
