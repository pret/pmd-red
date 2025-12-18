#ifndef GUARD_MUSIC_UTIL_H
#define GUARD_MUSIC_UTIL_H

enum MenuSFXID
{
    MENU_SFX_ACCEPT,
    MENU_SFX_BACK,
    MENU_SFX_FAIL,
    MENU_SFX_NAVIGATE,
    MENU_SFX_INFO,
    MENU_SFX_SORT,
    MENU_SFX_TOGGLE,
    MENU_SFX_COUNT
};

void ResetSoundEffectCounters(void);
void StopBGMResetSoundEffectCounters(void);
void StartBGMusic(void);
void UpdateSoundEffectCounters(void);
void StopAllMusic_1(void);
void FadeOutAllMusic(u16);
void StartNewBGM_(u16 songIndex);
void FadeInNewBGM_(u16 songIndex, u16 speed);
void QueueBGM_(u16 songIndex);
void StopBGMusic(void);
void FadeOutBGM_(u16 speed);
bool8 IsEqualtoBGTrack(u16 songIndex);
void PlaySoundWithVolume(u16 songIndex, u16 volume);
void PlaySound(u16 songIndex);
void StopSound(u16 songIndex);
void FadeOutSound(u16 songIndex, u16 speed);
bool8 IsSoundPlaying(u16 songIndex);
// id: See enum "MenuSFXID"
void PlayMenuSoundEffect(u32 id);
void PlayDialogueTextSound(void);

#endif // GUARD_MUSIC_UTIL_H
