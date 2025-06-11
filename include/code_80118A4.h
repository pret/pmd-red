#ifndef GUARD_CODE_80118A4_H
#define GUARD_CODE_80118A4_H

void FadeOutAllMusic(u16);
void PlayMenuSoundEffect(u32);
void PlaySound(u16);
void StopAllMusic_1(void);
void sub_801180C(void);
void sub_8011830(void);
void sub_8011860(void);
void FadeInNewBGM_(u16 songIndex, u16 speed);
void FadeOutBGM_(u16 speed);
void FadeOutSound(u16 songIndex, u16 speed);
void QueueBGM_(u16 songIndex);
void PlaySoundWithVolume(u16 songIndex, u16 volume);
void StartBGMusic(void);
void xxx_call_start_new_bgm(u16 songIndex);
void StopBGMusic(void);
void StopSound(u16 songIndex);

#endif // GUARD_CODE_80118A4_H
