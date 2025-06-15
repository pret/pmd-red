#include "global.h"
#include "globaldata.h"
#include "world_map_sound.h"
#include "music.h"
#include "constants/bg_music.h"
#include "event_flag.h"

// Also used for the friend areas map.

void PlayFriendAreasMapBGM(void)
{
    if (sub_80023E4(13))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else if (sub_80023E4(12))
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void PlayWorldMapBGM(void)
{
    if (sub_80023E4(13))
        StartNewBGM(MUS_WORLD_CALAMITY);
    else
        StartNewBGM(MUS_POKEMON_SQUARE);
}

void FadeOutFriendAreasMapBGM(void)
{
    if (!sub_80023E4(13))
        FadeOutBGM(30);
}

void FadeOutWorldMapBGM(void)
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
