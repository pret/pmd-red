#include "global.h"
#include "m4a.h"
#include "music.h"
#include "constants/bg_music.h"

EWRAM_DATA u16 gBGMusicPlayerState = {0};
EWRAM_DATA u16 gCurrentBGSong = {0};
EWRAM_DATA u16 gQueuedBGSong = {0};
EWRAM_DATA u16 gCurrentFanfareSong = {0};
EWRAM_DATA u16 gFanfareMusicPlayerState = {0};
EWRAM_DATA u16 gMusicTransitionCounter = {0};
EWRAM_DATA bool8 gRestartBGM = {0};

IWRAM_DATA struct PMDMusicPlayer gBGMusicPlayers[NUM_BG_PLAYERS] = {0};
IWRAM_DATA struct PMDMusicPlayer gSEMusicPlayers[NUM_SE_PLAYERS] = {0};

extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
void nullsub_21(u16);

void InitMusic(void)
{
    s32 playerIndex;

    struct PMDMusicPlayer *musicPlayer;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    m4aSoundInit();

    gBGMusicPlayerState = 0;
    gCurrentBGSong = STOP_BGM;
    gQueuedBGSong = STOP_BGM;
    gCurrentFanfareSong = STOP_SOUND_EFFECT;
    gFanfareMusicPlayerState = 0;
    gMusicTransitionCounter = 0;
    gRestartBGM = FALSE;

    for(playerIndex = INDEX_BGM, musicPlayer = &gBGMusicPlayers[0]; playerIndex < INDEX_SE6 + 1; playerIndex++, musicPlayer++)
    {
        musicPlayer->unk0 = 0;
        musicPlayer->songIndex = STOP_SOUND_EFFECT;
        musicPlayer->volume = 0;
        musicPlayer->isNotMaxVolume = FALSE;
    }
    nullsub_19();
}

void StopAllMusic(void)
{
    StopBGM();
    StopFanfareSE(STOP_FANFARE);
    StopFanfareSE(STOP_SOUND_EFFECT);
}

void StartNewBGM(u16 songIndex)
{
    bool8 interrupt_flag;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == STOP_BGM)
        return;
    if(songIndex == gCurrentBGSong)
    {
        if((u16)(gBGMusicPlayerState - 1) <= 1)
            return;
    }
    if(GetMusicPlayerIndex(songIndex) != INDEX_BGM)
    {
        nullsub_20(songIndex);
        return;
    }
    interrupt_flag = DisableInterrupts();
    gCurrentBGSong = songIndex;
    gRestartBGM = TRUE;

    if(gFanfareMusicPlayerState == 0)
    {
        gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeInNewBGM(u16 songIndex, u16 speed)
{
    bool8 interrupt_flag;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == STOP_BGM)
        return;
    if(songIndex == gCurrentBGSong)
    {
        if((u16)(gBGMusicPlayerState - 1) <= 1)
            return;
    }

    if((speed > 256))
    {
        speed = 16;

    }
    else
    {
        if((speed >>= 4) == 0)
        {
            speed = 1;
        }
    }

    interrupt_flag = DisableInterrupts();
    gCurrentBGSong = songIndex;
    gRestartBGM = TRUE;

    if(gFanfareMusicPlayerState == 0)
    {
        gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
        m4aMPlayImmInit(&gMPlayInfo_BGM);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0);
        m4aSongNumStop(songIndex);
        m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void QueueBGM(u16 songIndex)
{
    if(gCurrentBGSong == STOP_BGM)
    {
        StartNewBGM(songIndex);
        gQueuedBGSong = STOP_BGM;
    }
    else
        gQueuedBGSong = songIndex;
}

void StopBGM(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
        }
    }
    gCurrentBGSong = STOP_BGM;
    gQueuedBGSong = STOP_BGM;
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeOutBGM(u16 speed)
{
    bool8 interrupt_flag;

    if(speed > ((0x80 << 17) / 65536))
    {
        speed = 16;
    }
    else
    {
        if((speed >>= 4) == 0)
        {
            speed = 1;
        }
    }
    interrupt_flag = DisableInterrupts();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            if(gBGMusicPlayerState == 2)
            {
                gBGMusicPlayerState = 3;
                m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
            }
            else
            {
                gCurrentBGSong = STOP_BGM;
                m4aMPlayStop(&gMPlayInfo_BGM);
            }
        }
    }
    else
    {
        gCurrentBGSong = STOP_BGM;
    }
    gQueuedBGSong = STOP_BGM;
    if(interrupt_flag)
        EnableInterrupts();
}

u16 GetCurrentBGSong(void)
{
    return gCurrentBGSong;
}

void PlayFanfareSE(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  bool8 interrupt_flag2;
  u16 playerIndex;
  struct PMDMusicPlayer *musicPlayer;

  if (songIndex == STOP_SOUND_EFFECT)
    return;
  if (volume > MAX_VOLUME)
    volume = MAX_VOLUME;

  if (IsFanfare(songIndex)) 
  {
    if (GetMusicPlayerIndex(songIndex) == INDEX_FANFARE) {
      interrupt_flag = DisableInterrupts();
      gCurrentFanfareSong = songIndex;
      if(gFanfareMusicPlayerState == 0)
      {
        if (gCurrentBGSong != STOP_BGM) 
        {
            if ((u16)(gBGMusicPlayerState - 1) < 2)
            {
                gFanfareMusicPlayerState = 1;
                gMusicTransitionCounter = 16;
                gRestartBGM = FALSE;
                m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, 1);
            }
            else if (gBGMusicPlayerState == 3)
                gFanfareMusicPlayerState = 2;
            else
            {
                gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                m4aMPlayStop(&gMPlayInfo_BGM);
                m4aSongNumStart(gCurrentFanfareSong);
            }
        }
        else
        {
            gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
            m4aMPlayStop(&gMPlayInfo_BGM);
            m4aSongNumStart(gCurrentFanfareSong);
        }
      }
      else
      {
        if (1 < (u16)(gFanfareMusicPlayerState - 1)) 
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            m4aSongNumStart(gCurrentFanfareSong);
            gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
        }
      }
      switch(gCurrentBGSong)
      {
        case MUS_RAYQUAZAS_DOMAIN:
        case MUS_FRIEND_AREA_STRATOS_LOOKOUT:
        case MUS_FRIEND_AREA_RAINBOW_PEAK:
        case MUS_DREAM_EATER:
        case MUS_FRIEND_AREA_DEEPSEA_CURRENT:
        case MUS_FRIEND_AREA_SEAFLOOR_CAVE:
        case MUS_FRIEND_AREA_VOLCANIC_PIT:
        case MUS_FRIEND_AREA_CRYPTIC_CAVE:
        case MUS_THE_OTHER_SIDE:
        case MUS_THE_MOUNTAIN_OF_FIRE:
        case MUS_FRIEND_AREA_LEGENDARY_ISLAND:
        case MUS_FRIEND_AREA_SOUTHERN_ISLAND:
        case MUS_FRIEND_AREA_ENCLOSED_ISLAND:
        case MUS_FRIEND_AREA_FINAL_ISLAND:
        case MUS_FRIEND_AREA_HEALING_FOREST:
            gRestartBGM = TRUE;
            break;
        default:
            break;
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
    else
    {
        nullsub_20(songIndex);
    }
  }
  else
  {
    if (!IsSoundEffect(songIndex))
      return;
    playerIndex = GetMusicPlayerIndex(songIndex);
    musicPlayer = &gBGMusicPlayers[playerIndex]; // need to load this before comparison to match
    if (playerIndex < INDEX_SE1)
        nullsub_20(songIndex);
    else
    {
      interrupt_flag2 = DisableInterrupts();
      m4aSongNumStart(songIndex);
      musicPlayer->unk0 = 1;
      musicPlayer->songIndex = songIndex;
      if(volume == MAX_VOLUME)
      {
        musicPlayer->isNotMaxVolume = FALSE;
      }
      else
      {
        musicPlayer->isNotMaxVolume = TRUE;
      }
      musicPlayer->volume = volume;
      if (interrupt_flag2)
        EnableInterrupts();
    }
  }
}

void SetSoundEffectVolume(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  u16 playerIndex;
  struct MusicPlayerInfo *info;
  struct PMDMusicPlayer *musicPlayer;

  if (MAX_VOLUME < volume) {
    volume = MAX_VOLUME;
  }

  if ((!IsFanfare(songIndex)) && (IsSoundEffect(songIndex))) {
    playerIndex = GetMusicPlayerIndex(songIndex);
    info = gMPlayTable[playerIndex].info;
    musicPlayer = &gBGMusicPlayers[playerIndex];
    if (playerIndex >= INDEX_SE1) {
      interrupt_flag = DisableInterrupts();
      if (musicPlayer->songIndex == songIndex) {
        m4aMPlayVolumeControl(info, 0xf, volume);
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
  }
}

void StopFanfareSE(u16 songIndex)
{
    // Each section needs a var for interrupts..
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;

    u32 playerIndex;
    s32 playerIndex2;
    struct MusicPlayerInfo *info;
    struct PMDMusicPlayer *musicPlayer;
    struct PMDMusicPlayer *musicPlayer1;

    if (songIndex == STOP_SOUND_EFFECT) {
        cVar1 = DisableInterrupts();

        for(playerIndex2 = INDEX_SE1, musicPlayer1 = &gSEMusicPlayers[0]; playerIndex2 < INDEX_SE6; playerIndex2++, musicPlayer1++)
        {
            m4aMPlayStop(gMPlayTable[playerIndex2].info);
            musicPlayer1->unk0 = 0;
            musicPlayer1->songIndex = STOP_SOUND_EFFECT;
            musicPlayer1->volume = 0;
            musicPlayer1->isNotMaxVolume = FALSE;
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsSoundEffect(songIndex))
    {
        playerIndex = GetMusicPlayerIndex(songIndex);
        info = gMPlayTable[playerIndex].info;
        musicPlayer = &gBGMusicPlayers[playerIndex];
        if (playerIndex < INDEX_SE1) {
            nullsub_21(songIndex);
        }
        else {
            cVar2 = DisableInterrupts();
            if (musicPlayer->songIndex == songIndex) {
                m4aMPlayStop(info);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->isNotMaxVolume = FALSE;
            }
            if (cVar2 != '\0') {
                EnableInterrupts();
            }
        }
    }
    else if (songIndex == STOP_FANFARE)
    {
        cVar3 = DisableInterrupts();
        if (gFanfareMusicPlayerState != 0) {
            if (gCurrentFanfareSong != STOP_SOUND_EFFECT) {
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }
        if (cVar3 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsFanfare(songIndex))
    {
        cVar4 = DisableInterrupts();
        if (gFanfareMusicPlayerState != 0) {
            if (gCurrentFanfareSong == songIndex) {
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }
        if (cVar4 != '\0') {
            EnableInterrupts();
        }
    }
}

void FadeOutFanfareSE(u16 songIndex, u16 speed)
{
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;
    u32 comparison;
    s32 playerIndex2;
    u32 playerIndex;
    struct PMDMusicPlayer *musicPlayer;
    struct PMDMusicPlayer *musicPlayer1;
    struct MusicPlayerInfo *playerInfo;

    comparison = 0x80 << 17; // 16777216
    if((speed * 65536) > comparison)
    {
        speed = 16;
    }
    else
    {
        if((speed >>= 4) == 0)
        {
            speed = 1;
        }
    }

    if (songIndex == STOP_SOUND_EFFECT) {
        cVar1 = DisableInterrupts();
        for(playerIndex2 = INDEX_SE1, musicPlayer1 = &gSEMusicPlayers[0]; playerIndex2 < INDEX_SE6; playerIndex2++, musicPlayer1++)
        {
            if (musicPlayer1->songIndex != STOP_SOUND_EFFECT) {
                if (IsMusicPlayerPlaying(playerIndex2)) {
                    m4aMPlayFadeOut(gMPlayTable[playerIndex2].info,speed);
                }
                else {
                    m4aMPlayStop(gMPlayTable[playerIndex2].info);
                    musicPlayer1->unk0 = 0;
                    musicPlayer1->songIndex = STOP_SOUND_EFFECT;
                    musicPlayer1->volume = 0;
                    musicPlayer1->isNotMaxVolume = FALSE;
                }
            }
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsSoundEffect(songIndex)) {
        playerIndex = GetMusicPlayerIndex(songIndex);
        musicPlayer = &gBGMusicPlayers[playerIndex];
        playerInfo = gMPlayTable[playerIndex].info;
        cVar2 = DisableInterrupts();
        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) {
            if (IsMusicPlayerPlaying(playerIndex)) {
                m4aMPlayFadeOut(playerInfo,speed);
            }
            else {
                m4aMPlayStop(playerInfo);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->isNotMaxVolume = FALSE;
            }
        }
        if (cVar2 != '\0') {
            EnableInterrupts();
        }
    }
    else if (songIndex == STOP_FANFARE) {
        cVar3 = DisableInterrupts();
        if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong != STOP_SOUND_EFFECT)) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE)) {
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare,speed);
            }
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }
        if (cVar3 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsFanfare(songIndex)) {
        cVar4 = DisableInterrupts();
        if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong == songIndex)) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE)) {
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare,speed);
            }
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }
        if (cVar4 != '\0') {
            EnableInterrupts();
        }
    }
}

bool8 IsFanfareSEPlaying(u16 songIndex)
{
  u32 playerIndex;
  struct PMDMusicPlayer *musicPlayer;
#ifndef NONMATCHING
  register u32 songIndex_u32 asm("r4");
  register u32 songIndex_u32_2 asm("r5");
#else
  u32 songIndex_u32;
  u32 songIndex_u32_2;
#endif

  songIndex_u32 = songIndex;
  songIndex_u32_2 = songIndex_u32;

  if (IsFanfare(songIndex_u32)) {
    if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong == songIndex_u32)) {
      return TRUE;
    }
  }
  else
  {
    if (IsSoundEffect(songIndex_u32)) {
      playerIndex = GetMusicPlayerIndex(songIndex_u32);
      musicPlayer = &gBGMusicPlayers[playerIndex];
      if ((INDEX_SE1 <= playerIndex) && (musicPlayer->songIndex == songIndex_u32_2)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

void SoundVSync(void)
{
  u8 cVar1;

  cVar1 = DisableInterrupts();
  m4aSoundVSync();
  if(cVar1)
    EnableInterrupts();
}


void nullsub_18(void)
{
}

void UpdateSound(void)
{
    struct PMDMusicPlayer *musicPlayer; // r4
    s32 musicPlayerIndex; // r5
    
    m4aSoundMain();

    if(gFanfareMusicPlayerState != 0)
    {
        switch(gFanfareMusicPlayerState)
        {
            case 1:
                if (gMusicTransitionCounter != 0) 
                {
                    gMusicTransitionCounter--;
                }
                else if (gCurrentFanfareSong == STOP_SOUND_EFFECT) 
                {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                else
                {
                    m4aSongNumStart(gCurrentFanfareSong);
                    gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 2:
                if ((gCurrentBGSong != STOP_BGM) && (IsMusicPlayerPlaying(INDEX_BGM)))
                    break;
                if (gCurrentFanfareSong == STOP_SOUND_EFFECT)
                {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                else
                {
                    m4aSongNumStart(gCurrentFanfareSong);
                    gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 3:
                if ((gCurrentFanfareSong != STOP_SOUND_EFFECT) && (!IsMusicPlayerPlaying(INDEX_FANFARE))) // INDEX_FANFARE
                    break;
                else {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                break;
            case 4:
                if (gCurrentFanfareSong != STOP_SOUND_EFFECT) 
                {
                    if (IsMusicPlayerPlaying(INDEX_FANFARE)) break; // INDEX_FANFARE
                }
                else
                    m4aMPlayStop(&gMPlayInfo_Fanfare);

                if (gMusicTransitionCounter != 0) 
                {
                    gMusicTransitionCounter--;
                    break;
                }
                else if (gCurrentBGSong != STOP_BGM) 
                {
                    gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                    if (gRestartBGM)
                        m4aSongNumStart(gCurrentBGSong);
                    else
                        m4aMPlayFadeIn(&gMPlayInfo_BGM,4);
                }
                else 
                {
                    gBGMusicPlayerState = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                }
                gFanfareMusicPlayerState = 0;
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                break;
        }
    }
    else if (gBGMusicPlayerState != BG_PLAYER_STATE_INITIALIZE)
    {
        switch(gBGMusicPlayerState)
        {

            case BG_PLAYER_STATE_PLAYING:
                if ((gCurrentBGSong == STOP_BGM) || IsMusicPlayerPlaying(INDEX_BGM)) // INDEX_BGM
                {
                    gBGMusicPlayerState = 2;
                }
                break;
            case 2:
            case 3:
                if (gCurrentBGSong != STOP_BGM) 
                {
                    if (IsMusicPlayerPlaying(INDEX_BGM)) break; // INDEX_BGM
                }
                else
                    m4aMPlayStop(&gMPlayInfo_BGM);
                gBGMusicPlayerState = 0;
                gCurrentBGSong = STOP_BGM;
                break;
            case BG_PLAYER_STATE_STOPPED: // can also be other constants
                break;
        }
    }
    else
    {
        if (!IsMusicPlayerPlaying(INDEX_BGM)) 
        {
#ifndef NONMATCHING
            register u16 r2 asm("r2") = gQueuedBGSong, r1 = r2;
#else
            u16 r2, r1;
            r2 = gQueuedBGSong, r1 = r2;
#endif
            if (r1 != STOP_BGM) 
            {
                gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                gCurrentBGSong = r2;
                m4aSongNumStart(r1);
                gQueuedBGSong = STOP_BGM;
            }
            else 
            {
                gBGMusicPlayerState = 0;
                gCurrentBGSong = STOP_BGM;
            }
        }
    }

    for(musicPlayerIndex = INDEX_SE1,  musicPlayer = &gSEMusicPlayers[0]; musicPlayerIndex < INDEX_SE6; musicPlayerIndex++, musicPlayer++)
    {
        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) 
        {
            switch(musicPlayer->unk0)
            {
                    case 1:
                        if ((musicPlayer->songIndex == STOP_BGM) || (IsMusicPlayerPlaying(musicPlayerIndex))) 
                        {
                            musicPlayer->unk0 = 2;
                        }
                        break;
                    case 2:
                        if (IsMusicPlayerPlaying(musicPlayerIndex))
                        {
                            if(musicPlayer->isNotMaxVolume)
                            {
                                musicPlayer->isNotMaxVolume = FALSE;
                                m4aMPlayVolumeControl(gMPlayTable[musicPlayerIndex].info,0xff,musicPlayer->volume);
                            }
                        }
                        else 
                        {
                            musicPlayer->unk0 = 0;
                            musicPlayer->songIndex = STOP_SOUND_EFFECT;
                            musicPlayer->volume = 0;
                            musicPlayer->isNotMaxVolume = FALSE;
                        }
                        break;
                    case 3:
                    case 0:
                        break;
            }
        }
    }
}

void StopBGMusicVSync(void)
{
    bool8 interrupt_flag;
    u16 temp;

    FadeOutFanfareSE(STOP_SOUND_EFFECT, 0x10);
    FadeOutFanfareSE(STOP_FANFARE, 0x10);

    interrupt_flag = DisableInterrupts();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            temp = gBGMusicPlayerState - 1;
            if(temp <= 1)
            {
                if(gBGMusicPlayerState == 2)
                {
                    gRestartBGM = FALSE;
                }
                else if(gBGMusicPlayerState == BG_PLAYER_STATE_PLAYING)
                {
                    gRestartBGM = TRUE;
                }
                gBGMusicPlayerState = BG_PLAYER_STATE_STOPPED;
            }
        }
    }
    m4aMPlayStop(&gMPlayInfo_BGM);
    m4aSoundVSyncOff();
    if(interrupt_flag)
    {
        EnableInterrupts();
    }
}

void StartBGMusicVSync(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    m4aSoundVSyncOn();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            if(gBGMusicPlayerState == BG_PLAYER_STATE_STOPPED)
            {
                gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                if(gRestartBGM)
                {
                    m4aSongNumStart(gCurrentBGSong);
                }
                else
                {
                    m4aMPlayContinue(&gMPlayInfo_BGM);
                }
            }
        }
    }
    if(interrupt_flag)
    {
        EnableInterrupts();
    }

}

void nullsub_179(void)
{
}

// Unused
bool8 IsValidSong(u32 songIndex)
{
    if(IsBGSong(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_BGM)
        {
            return TRUE;
        }
    }
    if(IsFanfare(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_FANFARE)
        {
            return TRUE;
        }
    }
    else if(IsSoundEffect(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) >= INDEX_SE1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void nullsub_19(void)
{
}

bool8 IsBGSong(u32 songIndex)
{
    if(songIndex <= NUM_BG_SONGS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsSoundEffect(u32 songIndex)
{
    if(songIndex - SOUND_EFFECTS_START_INDEX <= NUM_SOUND_EFFECTS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFanfare(u32 songIndex)
{
    if(songIndex - FANFARE_START_INDEX <= NUM_FANFARES)
    {
        return TRUE;
    }
    return FALSE;
}

u16 GetMusicPlayerIndex(u16 songIndex)
{
    return gSongTable[songIndex].ms;
}

bool8 IsMusicPlayerPlaying(u16 playerIndex)
{
    // Had to cast this.. m4a_internal header has this as u32
    if((u16)gMPlayTable[playerIndex].info->status == 0)
    {
        return FALSE;
    }
    return TRUE;
}

void nullsub_20(u16 songIndex)
{
}

void nullsub_21(u16 songIndex)
{
}

