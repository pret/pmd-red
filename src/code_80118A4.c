#include <stdarg.h>
#include <stdio.h>
#include "global.h"
#include "music.h"
#include "constants/bg_music.h"
#include "play_time.h"
#include "bg.h"
#include "input.h"
#include "config.h"
#include "game_options.h"

void xxx_call_stop_bgm(void);

extern bool8 sub_80023E4(u8);
extern void xxx_call_stop_fanfare_se(u16 r0);

extern struct GameOptions *gGameOptions;

struct UnkBgStruct
{
    u8 padding[0x4c4b];
    u32 unk4c4c;
    u8 padding2[0x17A];
    u32 *unk4dcc;
    u32 unk4dd0;
    s16 xoffset;
    s16 yoffset;
};
extern struct UnkBgStruct *gUnknown_203B0E4;


extern const u16 gUnknown_80D4144[8];
EWRAM_DATA u32 gUnknown_202DE1C;
EWRAM_DATA s16 gUnknown_202DE20;
EWRAM_DATA s16 gUnknown_202DE22;
EWRAM_DATA s16 gUnknown_202DE24;

void nullsub_8(u32);
void sub_8005838(u32, u32);
extern void CopySpritesToOam(void);
extern void sub_8005304(void);
extern void TransferBGPaletteBuffer(void);
extern void xxx_call_update_bg_vram(void);
extern void sub_8009908(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_8005180(void);
extern void sub_80060EC(void);
extern void sub_8011860(void);
extern void sub_800CB20(void);
extern void ResetSprites(u32);
extern void sub_8004AF0(u8, u32 *r1, u32, u32, u32 *r2, u32);
extern u8 sub_80111C4();
extern void sub_8010F28();

void sub_801169C(void)
{
    u8 return_var;

    SetBG2RegOffsets(gUnknown_203B0E4->xoffset, gUnknown_203B0E4->yoffset);
    SetBG3RegOffsets(gUnknown_203B0E4->xoffset, gUnknown_203B0E4->yoffset);
    sub_8010F28();
    return_var = sub_80111C4();
    sub_8004AF0(return_var, &(gUnknown_203B0E4->unk4c4c), 0xB0, 0x10, (gUnknown_203B0E4->unk4dcc), 0);
    sub_8005838(0, 0);
    nullsub_8(gGameOptions->unkA);
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
    ResetSprites(0);
}

void sub_8011760(void)
{
    if(sub_80023E4(0xD))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else if(sub_80023E4(0xC))
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void sub_801178C(void)
{
    if(sub_80023E4(0xD))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void sub_80117AC(void)
{
    if(!sub_80023E4(0xD))
        FadeOutBGM(0x1E);
}

void sub_80117C4(void)
{
    FadeOutBGM(0x1E);
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
    if(gUnknown_202DE20 > 0)
    {
        gUnknown_202DE20--;
    }
    if(gUnknown_202DE22 > 0)
    {
        gUnknown_202DE22--;
    }
    if(gUnknown_202DE24 > 0)
    {
        gUnknown_202DE24--;
    }
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

u32 IsEqualtoBGTrack(u16 songIndex)
{
    u32 currBGSong;
    currBGSong = GetCurrentBGSong();

    if(songIndex == STOP_BGM)
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

void PlayMenuSoundEffect(u32 r0)
{
    if(gUnknown_202DE20 > 0)
        return;
    PlayFanfareSE(gUnknown_80D4144[r0], MAX_VOLUME);
    gUnknown_202DE20 = 4;
}

void sub_8011A04(void)
{
    if(gUnknown_202DE22 > 0)
        return;
    gUnknown_202DE22 = 3;
    PlayFanfareSE(305, MAX_VOLUME);
}

void sub_8011A2C(u32 r0)
{
    gUnknown_202DE1C = r0;
}
