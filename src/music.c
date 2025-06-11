#include "global.h"
#include "constants/bg_music.h"
#include "m4a.h"
#include "reg_control.h"
#include "music.h"

static EWRAM_DATA u16 sBGMusicPlayerstate = {0};
static EWRAM_DATA u16 sCurrentBGSong = {0};
static EWRAM_DATA u16 sQueuedBGSong = {0};
static EWRAM_DATA u16 sCurrentFanfareSong = {0};
static EWRAM_DATA u16 sFanfareMusicPlayerState = {0};
static EWRAM_DATA u16 sMusicTransitionCounter = {0};
static EWRAM_DATA bool8 sRestartBGM = {0};

static IWRAM_DATA PMDMusicPlayer sMusicPlayers[MUSIC_PLAYERS_COUNT] = {0};

static u16 GetMusicPlayerIndex(u16 songIndex);
static bool8 IsBGSong(u32 songIndex);
static bool8 IsFanfare(u32 songIndex);
static bool8 IsMusicPlayerPlaying(u16 playerIndex);
static bool8 IsSoundEffect(u32 songIndex);

static void nullsub_19(void);
static void nullsub_20(u16 songIndex);
static void nullsub_21(u16 songIndex);

void InitMusic(void)
{
    s32 playerIndex;

    PMDMusicPlayer *musicPlayer;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    m4aSoundInit();

    sBGMusicPlayerstate = 0;
    sCurrentBGSong = STOP_BGM;
    sQueuedBGSong = STOP_BGM;
    sCurrentFanfareSong = STOP_SOUND_EFFECT;
    sFanfareMusicPlayerState = 0;
    sMusicTransitionCounter = 0;
    sRestartBGM = FALSE;

    for (playerIndex = INDEX_BGM, musicPlayer = &sMusicPlayers[0]; playerIndex < MUSIC_PLAYERS_COUNT; playerIndex++, musicPlayer++) {
        musicPlayer->unk0 = 0;
        musicPlayer->songIndex = STOP_SOUND_EFFECT;
        musicPlayer->volume = 0;
        musicPlayer->isNotMaxVolume = FALSE;
    }

    nullsub_19();
}

UNUSED static void StopAllMusic(void)
{
    StopBGM();
    StopFanfareSE(STOP_FANFARE);
    StopFanfareSE(STOP_SOUND_EFFECT);
}

void StartNewBGM(u16 songIndex)
{
    bool8 interruptFlag;

    if (!IsBGSong(songIndex))
        return;
    if (songIndex == STOP_BGM)
        return;
    if (songIndex == sCurrentBGSong) {
        if (sBGMusicPlayerstate == 1 || sBGMusicPlayerstate == 2)
            return;
    }
    if (GetMusicPlayerIndex(songIndex) != INDEX_BGM) {
        nullsub_20(songIndex);
        return;
    }

    interruptFlag = DisableInterrupts();
    sCurrentBGSong = songIndex;
    sRestartBGM = TRUE;

    if (sFanfareMusicPlayerState == 0) {
        sBGMusicPlayerstate = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
    }
    if (interruptFlag)
        EnableInterrupts();
}

void FadeInNewBGM(u16 songIndex, u16 speed)
{
    bool8 interruptFlag;

    if (!IsBGSong(songIndex))
        return;
    if (songIndex == STOP_BGM)
        return;
    if (songIndex == sCurrentBGSong) {
        if (sBGMusicPlayerstate == 1 || sBGMusicPlayerstate == 2)
            return;
    }

    if (speed > 256)
        speed = 16;
    else {
        speed >>= 4;
        if (speed == 0)
            speed = 1;
    }

    interruptFlag = DisableInterrupts();
    sCurrentBGSong = songIndex;
    sRestartBGM = TRUE;

    if (sFanfareMusicPlayerState == 0) {
        sBGMusicPlayerstate = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
        m4aMPlayImmInit(&gMPlayInfo_BGM);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0);
        m4aSongNumStop(songIndex);
        m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
    }

    if (interruptFlag)
        EnableInterrupts();
}

void QueueBGM(u16 songIndex)
{
    if (sCurrentBGSong == STOP_BGM) {
        StartNewBGM(songIndex);
        sQueuedBGSong = STOP_BGM;
    }
    else
        sQueuedBGSong = songIndex;
}

void StopBGM(void)
{
    bool8 interruptFlag = DisableInterrupts();

    if (sFanfareMusicPlayerState == 0) {
        if (sCurrentBGSong != STOP_BGM)
            m4aMPlayStop(&gMPlayInfo_BGM);
    }

    sCurrentBGSong = STOP_BGM;
    sQueuedBGSong = STOP_BGM;

    if (interruptFlag)
        EnableInterrupts();
}

void FadeOutBGM(u16 speed)
{
    bool8 interruptFlag;

    if (speed > 256) {
        speed = 16;
    }
    else {
        speed >>= 4;
        if (speed == 0)
            speed = 1;
    }

    interruptFlag = DisableInterrupts();

    if (sFanfareMusicPlayerState == 0) {
        if (sCurrentBGSong != STOP_BGM) {
            if (sBGMusicPlayerstate == 2) {
                sBGMusicPlayerstate = 3;
                m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
            }
            else {
                sCurrentBGSong = STOP_BGM;
                m4aMPlayStop(&gMPlayInfo_BGM);
            }
        }
    }
    else
        sCurrentBGSong = STOP_BGM;

    sQueuedBGSong = STOP_BGM;

    if (interruptFlag)
        EnableInterrupts();
}

u16 GetCurrentBGSong(void)
{
    return sCurrentBGSong;
}

// arm9.bin::0200ADB8
void PlayFanfareSE(u16 songIndex, u16 volume)
{
    u16 playerIndex;
    PMDMusicPlayer *musicPlayer;

    if (songIndex == STOP_SOUND_EFFECT)
        return;
    if (volume > MAX_VOLUME)
        volume = MAX_VOLUME;

    if (IsFanfare(songIndex)) {
        if (GetMusicPlayerIndex(songIndex) == INDEX_FANFARE) {
            bool8 interruptFlag = DisableInterrupts();
            sCurrentFanfareSong = songIndex;
            if (sFanfareMusicPlayerState == 0) {
                if (sCurrentBGSong != STOP_BGM) {
                    if (sBGMusicPlayerstate == 1 || sBGMusicPlayerstate == 2) {
                        sFanfareMusicPlayerState = 1;
                        sMusicTransitionCounter = 16;
                        sRestartBGM = FALSE;
                        m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, 1);
                    }
                    else if (sBGMusicPlayerstate == 3)
                        sFanfareMusicPlayerState = 2;
                    else {
                        sFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                        m4aMPlayStop(&gMPlayInfo_BGM);
                        m4aSongNumStart(sCurrentFanfareSong);
                    }
                }
                else {
                    sFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    m4aSongNumStart(sCurrentFanfareSong);
                }
            }
            else {
                if (sFanfareMusicPlayerState != 1 && sFanfareMusicPlayerState != 2) {
                    m4aMPlayStop(&gMPlayInfo_BGM);
                    m4aSongNumStart(sCurrentFanfareSong);
                    sFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
            }

            switch (sCurrentBGSong) {
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
                    sRestartBGM = TRUE;
                    break;
                default:
                    break;
            }

            if (interruptFlag)
                EnableInterrupts();
        }
        else
            nullsub_20(songIndex);
    }
    else {
        if (!IsSoundEffect(songIndex))
            return;

        playerIndex = GetMusicPlayerIndex(songIndex);
        musicPlayer = &sMusicPlayers[playerIndex]; // need to load this before comparison to match

        if (playerIndex < INDEX_SE1)
            nullsub_20(songIndex);
        else
        {
            bool8 interruptFlag = DisableInterrupts();
            m4aSongNumStart(songIndex);
            musicPlayer->unk0 = 1;
            musicPlayer->songIndex = songIndex;

            if (volume == MAX_VOLUME)
                musicPlayer->isNotMaxVolume = FALSE;
            else
                musicPlayer->isNotMaxVolume = TRUE;

            musicPlayer->volume = volume;
            if (interruptFlag)
                EnableInterrupts();
        }
    }
}

UNUSED static void SetSoundEffectVolume(u16 songIndex, u16 volume)
{
    bool8 interruptFlag;
    u16 playerIndex;
    struct MusicPlayerInfo *info;
    PMDMusicPlayer *musicPlayer;

    if (MAX_VOLUME < volume)
        volume = MAX_VOLUME;

    if (!IsFanfare(songIndex) && IsSoundEffect(songIndex)) {
        playerIndex = GetMusicPlayerIndex(songIndex);
        info = gMPlayTable[playerIndex].info;
        musicPlayer = &sMusicPlayers[playerIndex];
        if (playerIndex >= INDEX_SE1) {
            interruptFlag = DisableInterrupts();
            if (musicPlayer->songIndex == songIndex)
                m4aMPlayVolumeControl(info, 0xf, volume);

            if (interruptFlag)
                EnableInterrupts();
        }
    }
}

void StopFanfareSE(u16 songIndex)
{
    if (songIndex == STOP_SOUND_EFFECT) {
        s32 playerIndex;
        PMDMusicPlayer *musicPlayer;
        bool8 interruptFlag = DisableInterrupts();

        for (playerIndex = INDEX_SE1, musicPlayer = &sMusicPlayers[INDEX_SE1]; playerIndex < INDEX_SE6; playerIndex++, musicPlayer++) {
            m4aMPlayStop(gMPlayTable[playerIndex].info);
            musicPlayer->unk0 = 0;
            musicPlayer->songIndex = STOP_SOUND_EFFECT;
            musicPlayer->volume = 0;
            musicPlayer->isNotMaxVolume = FALSE;
        }

        if (interruptFlag)
            EnableInterrupts();
    }
    else if (IsSoundEffect(songIndex)) {
        u32 playerIndex = GetMusicPlayerIndex(songIndex);
        struct MusicPlayerInfo *info = gMPlayTable[playerIndex].info;
        PMDMusicPlayer *musicPlayer = &sMusicPlayers[playerIndex];

        if (playerIndex < INDEX_SE1)
            nullsub_21(songIndex);
        else {
            bool8 interruptFlag = DisableInterrupts();

            if (musicPlayer->songIndex == songIndex) {
                m4aMPlayStop(info);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->isNotMaxVolume = FALSE;
            }

            if (interruptFlag)
                EnableInterrupts();
        }
    }
    else if (songIndex == STOP_FANFARE) {
        bool8 interruptFlag = DisableInterrupts();

        if (sFanfareMusicPlayerState != 0) {
            if (sCurrentFanfareSong != STOP_SOUND_EFFECT) {
                sCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
    else if (IsFanfare(songIndex)) {
        bool8 interruptFlag = DisableInterrupts();

        if (sFanfareMusicPlayerState != 0) {
            if (sCurrentFanfareSong == songIndex) {
                sCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
}

void FadeOutFanfareSE(u16 songIndex, u16 speed)
{
    if (speed > 256) {
        speed = 16;
    }
    else {
        speed >>= 4;
        if (speed == 0)
            speed = 1;
    }

    if (songIndex == STOP_SOUND_EFFECT) {
        s32 playerIndex;
        PMDMusicPlayer *musicPlayer;
        bool8 interruptFlag = DisableInterrupts();

        for (playerIndex = INDEX_SE1, musicPlayer = &sMusicPlayers[INDEX_SE1]; playerIndex < INDEX_SE6; playerIndex++, musicPlayer++) {
            if (musicPlayer->songIndex != STOP_SOUND_EFFECT) {
                if (IsMusicPlayerPlaying(playerIndex))
                    m4aMPlayFadeOut(gMPlayTable[playerIndex].info, speed);
                else {
                    m4aMPlayStop(gMPlayTable[playerIndex].info);
                    musicPlayer->unk0 = 0;
                    musicPlayer->songIndex = STOP_SOUND_EFFECT;
                    musicPlayer->volume = 0;
                    musicPlayer->isNotMaxVolume = FALSE;
                }
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
    else if (IsSoundEffect(songIndex)) {
        s32 playerIndex = GetMusicPlayerIndex(songIndex);
        PMDMusicPlayer *musicPlayer = &sMusicPlayers[playerIndex];
        struct MusicPlayerInfo *playerInfo = gMPlayTable[playerIndex].info;
        bool8 interruptFlag = DisableInterrupts();

        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) {
            if (IsMusicPlayerPlaying(playerIndex))
                m4aMPlayFadeOut(playerInfo, speed);
            else {
                m4aMPlayStop(playerInfo);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->isNotMaxVolume = FALSE;
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
    else if (songIndex == STOP_FANFARE) {
        bool8 interruptFlag = DisableInterrupts();

        if (sFanfareMusicPlayerState != 0 && sCurrentFanfareSong != STOP_SOUND_EFFECT) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE))
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare, speed);
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                sCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
    else if (IsFanfare(songIndex)) {
        bool8 interruptFlag = DisableInterrupts();

        if (sFanfareMusicPlayerState != 0 && sCurrentFanfareSong == songIndex) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE))
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare, speed);
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                sCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }

        if (interruptFlag)
            EnableInterrupts();
    }
}

bool8 IsFanfareSEPlaying(u16 songIndex)
{
    u32 playerIndex;
    PMDMusicPlayer *musicPlayer;

    if (IsFanfare(songIndex)) {
        if (sFanfareMusicPlayerState != 0 && sCurrentFanfareSong == songIndex)
            return TRUE;
    }
    else if (IsSoundEffect(songIndex)) {
        playerIndex = GetMusicPlayerIndex(songIndex);
        musicPlayer = &sMusicPlayers[playerIndex];
        if (INDEX_SE1 > playerIndex)
            return FALSE;
        if (musicPlayer->songIndex == songIndex)
            return TRUE;
    }

    return FALSE;
}

void SoundVSync(void)
{
    bool8 interruptFlag = DisableInterrupts();

    m4aSoundVSync();

    if (interruptFlag)
        EnableInterrupts();
}

void nullsub_18(void)
{
}

void UpdateSound(void)
{
    PMDMusicPlayer *musicPlayer;
    s32 musicPlayerIndex;

    m4aSoundMain();

    if (sFanfareMusicPlayerState != 0) {
        switch (sFanfareMusicPlayerState) {
            case 1:
                if (sMusicTransitionCounter != 0)
                    sMusicTransitionCounter--;
                else if (sCurrentFanfareSong == STOP_SOUND_EFFECT) {
                    sFanfareMusicPlayerState = 4;
                    sMusicTransitionCounter = 32;
                }
                else {
                    m4aSongNumStart(sCurrentFanfareSong);
                    sFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 2:
                if (sCurrentBGSong != STOP_BGM && IsMusicPlayerPlaying(INDEX_BGM))
                    break;

                if (sCurrentFanfareSong == STOP_SOUND_EFFECT) {
                    sFanfareMusicPlayerState = 4;
                    sMusicTransitionCounter = 32;
                }
                else {
                    m4aSongNumStart(sCurrentFanfareSong);
                    sFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 3:
                if (sCurrentFanfareSong != STOP_SOUND_EFFECT && !IsMusicPlayerPlaying(INDEX_FANFARE)) // INDEX_FANFARE
                    break;

                sFanfareMusicPlayerState = 4;
                sMusicTransitionCounter = 32;
                break;
            case 4:
                if (sCurrentFanfareSong != STOP_SOUND_EFFECT) {
                    if (IsMusicPlayerPlaying(INDEX_FANFARE))
                        break; // INDEX_FANFARE
                }
                else
                    m4aMPlayStop(&gMPlayInfo_Fanfare);

                if (sMusicTransitionCounter != 0) {
                    sMusicTransitionCounter--;
                    break;
                }

                if (sCurrentBGSong != STOP_BGM) {
                    sBGMusicPlayerstate = BG_PLAYER_STATE_PLAYING;

                    if (sRestartBGM)
                        m4aSongNumStart(sCurrentBGSong);
                    else
                        m4aMPlayFadeIn(&gMPlayInfo_BGM,4);
                }
                else {
                    sBGMusicPlayerstate = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                }

                sFanfareMusicPlayerState = 0;
                sCurrentFanfareSong = STOP_SOUND_EFFECT;
                break;
        }
    }
    else if (sBGMusicPlayerstate != BG_PLAYER_STATE_INITIALIZE) {
        switch (sBGMusicPlayerstate) {
            case BG_PLAYER_STATE_PLAYING:
                if (sCurrentBGSong == STOP_BGM || IsMusicPlayerPlaying(INDEX_BGM))
                    sBGMusicPlayerstate = 2;
                break;
            case 2:
            case 3:
                if (sCurrentBGSong != STOP_BGM) {
                    if (IsMusicPlayerPlaying(INDEX_BGM))
                        break;
                }
                else
                    m4aMPlayStop(&gMPlayInfo_BGM);

                sBGMusicPlayerstate = 0;
                sCurrentBGSong = STOP_BGM;
                break;
            case BG_PLAYER_STATE_STOPPED: // Can also be other constants
                break;
        }
    }
    else {
        if (!IsMusicPlayerPlaying(INDEX_BGM)) {
            u32 queuedBgSong = sQueuedBGSong;

            if (sQueuedBGSong != STOP_BGM) {
                sBGMusicPlayerstate = BG_PLAYER_STATE_PLAYING;
                sCurrentBGSong = queuedBgSong;
                m4aSongNumStart(queuedBgSong);
                sQueuedBGSong = STOP_BGM;
            }
            else {
                sBGMusicPlayerstate = 0;
                sCurrentBGSong = STOP_BGM;
            }
        }
    }

    for (musicPlayerIndex = INDEX_SE1,  musicPlayer = &sMusicPlayers[INDEX_SE1]; musicPlayerIndex < INDEX_SE6; musicPlayerIndex++, musicPlayer++) {
        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) {
            switch (musicPlayer->unk0){
                case 1:
                    if (musicPlayer->songIndex == STOP_BGM || IsMusicPlayerPlaying(musicPlayerIndex))
                        musicPlayer->unk0 = 2;
                    break;
                case 2:
                    if (IsMusicPlayerPlaying(musicPlayerIndex)) {
                        if (musicPlayer->isNotMaxVolume) {
                            musicPlayer->isNotMaxVolume = FALSE;
                            m4aMPlayVolumeControl(gMPlayTable[musicPlayerIndex].info, 0xFF, musicPlayer->volume);
                        }
                    }
                    else {
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
    bool8 interruptFlag;

    FadeOutFanfareSE(STOP_SOUND_EFFECT, 0x10);
    FadeOutFanfareSE(STOP_FANFARE, 0x10);

    interruptFlag = DisableInterrupts();

    if (sFanfareMusicPlayerState == 0) {
        if (sCurrentBGSong != STOP_BGM) {
            if (sBGMusicPlayerstate == 1 || sBGMusicPlayerstate == 2) {
                if (sBGMusicPlayerstate == 2)
                    sRestartBGM = FALSE;
                else if (sBGMusicPlayerstate == BG_PLAYER_STATE_PLAYING)
                    sRestartBGM = TRUE;

                sBGMusicPlayerstate = BG_PLAYER_STATE_STOPPED;
            }
        }
    }

    m4aMPlayStop(&gMPlayInfo_BGM);
    m4aSoundVSyncOff();

    if (interruptFlag)
        EnableInterrupts();
}

void StartBGMusicVSync(void)
{
    bool8 interruptFlag = DisableInterrupts();

    m4aSoundVSyncOn();

    if (sFanfareMusicPlayerState == 0) {
        if (sCurrentBGSong != STOP_BGM) {
            if (sBGMusicPlayerstate == BG_PLAYER_STATE_STOPPED) {
                sBGMusicPlayerstate = BG_PLAYER_STATE_PLAYING;

                if (sRestartBGM)
                    m4aSongNumStart(sCurrentBGSong);
                else
                    m4aMPlayContinue(&gMPlayInfo_BGM);
            }
        }
    }

    if (interruptFlag)
        EnableInterrupts();
}

UNUSED static void nullsub_179(void)
{
}

UNUSED static bool8 IsValidSong(u32 songIndex)
{
    if (IsBGSong(songIndex)) {
        if (GetMusicPlayerIndex(songIndex) == INDEX_BGM)
            return TRUE;
    }

    if (IsFanfare(songIndex)) {
        if (GetMusicPlayerIndex(songIndex) == INDEX_FANFARE)
            return TRUE;
    }
    else if (IsSoundEffect(songIndex)) {
        if (GetMusicPlayerIndex(songIndex) >= INDEX_SE1)
            return TRUE;
    }

    return FALSE;
}

static void nullsub_19(void)
{
}

static bool8 IsBGSong(u32 songIndex)
{
    if (songIndex <= NUM_BG_SONGS)
        return TRUE;
    return FALSE;
}

static bool8 IsSoundEffect(u32 songIndex)
{
    if (songIndex - SOUND_EFFECTS_START_INDEX <= NUM_SOUND_EFFECTS)
        return TRUE;
    return FALSE;
}

static bool8 IsFanfare(u32 songIndex)
{
    if (songIndex - FANFARE_START_INDEX <= NUM_FANFARES)
        return TRUE;
    return FALSE;
}

static u16 GetMusicPlayerIndex(u16 songIndex)
{
    return gSongTable[songIndex].ms;
}

static bool8 IsMusicPlayerPlaying(u16 playerIndex)
{
    // Had to cast this.. m4a_internal header has this as u32
    if ((u16)gMPlayTable[playerIndex].info->status == 0)
        return FALSE;
    return TRUE;
}

static void nullsub_20(u16 songIndex)
{
}

static void nullsub_21(u16 songIndex)
{
}
