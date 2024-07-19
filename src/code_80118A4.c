#include <stdarg.h>
#include <stdio.h>
#include "global.h"
#include "bg_palette_buffer.h"
#include "code_8004AA0.h"
#include "code_800558C.h"
#include "code_8009804.h"
#include "code_800C9CC.h"
#include "code_80118A4.h"
#include "music.h"
#include "constants/bg_music.h"
#include "play_time.h"
#include "bg_control.h"
#include "config.h"
#include "game_options.h"
#include "sprite.h"
#include "event_flag.h"
#include "file_system.h"

// size: 0x4DD8
struct UnkBgStruct
{
    OpenedFile *unk0[5];
    u8 padding[0x4C4C - 0x14];
    unkStruct_202EE8C unk4C4C[16];
    u32 unk4DCC;
    u32 unk4DD0;
    /* 0x4DD4 */ s16 xoffset;
    /* 0x4DD6 */ s16 yoffset;
};
extern struct UnkBgStruct *gUnknown_203B0E4;


extern const u16 gUnknown_80D4144[8];
EWRAM_DATA u32 gUnknown_202DE1C;
EWRAM_DATA s16 gUnknown_202DE20;
EWRAM_DATA s16 gUnknown_202DE22;
EWRAM_DATA s16 gUnknown_202DE24;

void nullsub_8(u32);
extern void xxx_call_update_bg_vram(void);
extern bool8 sub_80111C4();
extern void sub_8010F28();

void sub_801169C(void)
{
    SetBG2RegOffsets(gUnknown_203B0E4->xoffset, gUnknown_203B0E4->yoffset);
    SetBG3RegOffsets(gUnknown_203B0E4->xoffset, gUnknown_203B0E4->yoffset);
    sub_8010F28();
    sub_8004AF0(sub_80111C4(), gUnknown_203B0E4->unk4C4C, 0xB0, 16, gUnknown_203B0E4->unk4DCC, NULL);
    sub_8005838(NULL, 0);
    nullsub_8(gGameOptionsRef->unkA);
    sub_8005180();
    sub_80060EC();
    IncrementPlayTime(gPlayTimeRef);
    sub_800CB20();
    LoadBufferedInputs();
    CopySpritesToOam();
    sub_8005304();
    TransferBGPaletteBuffer();
    xxx_call_update_bg_vram();
    sub_8009908();
    xxx_call_update_bg_sound_input();
    sub_8011860();
    ResetSprites(FALSE);
}

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

// Some sound effect
void sub_80117D0(void)
{
    PlayFanfareSE(302, MAX_VOLUME);
}

// Some sound effect
void sub_80117E4(void)
{
    PlayFanfareSE(303, MAX_VOLUME);
}

// Some sound effect
void sub_80117F8(void)
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