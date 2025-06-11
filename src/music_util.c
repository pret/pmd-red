#include "global.h"
#include "globaldata.h"
#include "code_80118A4.h"
#include "music.h"
#include "constants/bg_music.h"

extern const u16 gUnknown_80D4144[8];

static EWRAM_DATA u32 gUnknown_202DE1C = {0}; // R=202DE1C | B=2134218
static EWRAM_DATA s16 gUnknown_202DE20 = {0}; // R=202DE20 | B=213420C
static EWRAM_DATA s16 gUnknown_202DE22 = {0}; // R=202DE22 | B=2134210
static EWRAM_DATA s16 gUnknown_202DE24 = {0}; // R=202DE24 | B=2134214

void sub_801180C(void)
{
    gUnknown_202DE1C = 0;
    gUnknown_202DE20 = 0;
    gUnknown_202DE22 = 0;
    gUnknown_202DE24 = 0;
}

void sub_8011830(void)
{
    StopBGMusicVSync();
    gUnknown_202DE20 = 0;
    gUnknown_202DE22 = 0;
    gUnknown_202DE24 = 0;
}

void StartBGMusic(void)
{
    StartBGMusicVSync();
}

// arm9.bin::020187C0
void sub_8011860(void)
{
    if (gUnknown_202DE20 > 0)
        gUnknown_202DE20--;

    if (gUnknown_202DE22 > 0)
        gUnknown_202DE22--;

    if (gUnknown_202DE24 > 0)
        gUnknown_202DE24--;
}

void StopAllMusic_1(void)
{
    StopBGMusic();
    StopSound(STOP_FANFARE);
    StopSound(STOP_SOUND_EFFECT);
}

void FadeOutAllMusic(u16 speed)
{
    FadeOutBGM(speed);
    FadeOutFanfareSE(STOP_FANFARE, speed);
    FadeOutFanfareSE(STOP_SOUND_EFFECT, speed);
}

void xxx_call_start_new_bgm(u16 songIndex)
{
    StartNewBGM(songIndex);
}

void FadeInNewBGM_(u16 songIndex, u16 speed)
{
    FadeInNewBGM(songIndex, speed);
}

void QueueBGM_(u16 songIndex)
{
    QueueBGM(songIndex);
}

void StopBGMusic(void)
{
    StopBGM();
}

void FadeOutBGM_(u16 speed)
{
    FadeOutBGM(speed);
}

bool8 IsEqualtoBGTrack(u16 songIndex)
{
    u32 currBGSong;
    currBGSong = GetCurrentBGSong();

    if (songIndex == STOP_BGM)
        return currBGSong != STOP_BGM;
    return currBGSong == songIndex;
}

void PlaySoundWithVolume(u16 songIndex, u16 volume)
{
    PlayFanfareSE(songIndex, volume);
}

// arm9.bin::020186c8
void PlaySound(u16 songIndex)
{
    PlayFanfareSE(songIndex, MAX_VOLUME);
}

void StopSound(u16 songIndex)
{
    StopFanfareSE(songIndex);
}

void FadeOutSound(u16 songIndex, u16 speed)
{
    FadeOutFanfareSE(songIndex, speed);
}

bool8 IsSoundPlaying(u16 songIndex)
{
    return IsFanfareSEPlaying(songIndex);
}

void PlayMenuSoundEffect(u32 a0)
{
    if (gUnknown_202DE20 > 0)
        return;

    PlayFanfareSE(gUnknown_80D4144[a0], MAX_VOLUME);
    gUnknown_202DE20 = 4;
}

void sub_8011A04(void)
{
    if (gUnknown_202DE22 > 0)
        return;

    gUnknown_202DE22 = 3;
    PlayFanfareSE(305, MAX_VOLUME);
}

UNUSED static void sub_8011A2C(u32 a0)
{
    gUnknown_202DE1C = a0;
}
