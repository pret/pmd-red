#include "global.h"
#include "structs/axdata.h"
#include "code_8009804.h"
#include "code_80118A4.h"
#include "music.h"
#include "constants/bg_music.h"
#include "config.h"
#include "event_flag.h"
#include "file_system.h"

extern const u16 gUnknown_80D4144[8];

EWRAM_DATA u32 gUnknown_202DE1C = {0}; // R=202DE1C | B=2134218
EWRAM_DATA s16 gUnknown_202DE20 = {0}; // R=202DE20 | B=213420C
EWRAM_DATA s16 gUnknown_202DE22 = {0}; // R=202DE22 | B=2134210
EWRAM_DATA s16 gUnknown_202DE24 = {0}; // R=202DE24 | B=2134214

void sub_8011760(void)
{
    if (sub_80023E4(13))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else if (sub_80023E4(12))
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void sub_801178C(void)
{
    if (sub_80023E4(13))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void sub_80117AC(void)
{
    if (!sub_80023E4(13))
        FadeOutBGM(30);
}

void sub_80117C4(void)
{
    FadeOutBGM(30);
}

// When you press A on a menu
void PlayAcceptSoundEffect(void)
{
    PlayFanfareSE(302, MAX_VOLUME);
}

// When you press B on a menu
void PlayCancelSoundEffect(void)
{
    PlayFanfareSE(303, MAX_VOLUME);
}

// When you go up or down
void PlayCursorUpDownSoundEffect(void)
{
    PlayFanfareSE(301, MAX_VOLUME);
}

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

void xxx_call_start_bg_music(void)
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
    xxx_call_stop_bgm();
    xxx_call_stop_fanfare_se(STOP_FANFARE);
    xxx_call_stop_fanfare_se(STOP_SOUND_EFFECT);
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

void xxx_call_fade_in_new_bgm(u16 songIndex, u16 speed)
{
    FadeInNewBGM(songIndex, speed);
}

void xxx_call_queue_bgm(u16 songIndex)
{
    QueueBGM(songIndex);
}

void xxx_call_stop_bgm()
{
    StopBGM();
}

void xxx_call_fade_out_bgm(u16 speed)
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

void xxx_call_play_fanfare_se(u16 songIndex, u16 volume)
{
    PlayFanfareSE(songIndex, volume);
}

// arm9.bin::020186c8
void PlaySound(u16 songIndex)
{
    PlayFanfareSE(songIndex, MAX_VOLUME);
}

void xxx_call_stop_fanfare_se(u16 songIndex)
{
    StopFanfareSE(songIndex);
}

void xxx_call_fade_out_fanfare_se(u16 songIndex, u16 speed)
{
    FadeOutFanfareSE(songIndex, speed);
}

bool8 IsFanfareSEPlaying_1(u16 songIndex)
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
