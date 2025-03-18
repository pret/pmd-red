#ifndef GUARD_CODE_80118A4_H
#define GUARD_CODE_80118A4_H

void FadeOutAllMusic(u16);
void PlayAcceptSoundEffect(void);
void PlayCancelSoundEffect(void);
void PlayCursorUpDownSoundEffect(void);
void PlayMenuSoundEffect(u32);
void PlaySound(u16);
void StopAllMusic_1(void);
void sub_8011760(void);
void sub_80117AC(void);
void sub_801180C(void);
void sub_8011830(void);
void sub_8011860(void);
void xxx_call_fade_in_new_bgm(u16 songIndex, u16 speed);
void xxx_call_fade_out_bgm(u16 speed);
void xxx_call_fade_out_fanfare_se(u16 songIndex, u16 speed);
void xxx_call_queue_bgm(u16 songIndex);
void xxx_call_play_fanfare_se(u16 songIndex, u16 volume);
void xxx_call_start_bg_music(void);
void xxx_call_start_new_bgm(u16 songIndex);
void xxx_call_stop_bgm(void);
void xxx_call_stop_fanfare_se(u16 songIndex);

#endif // GUARD_CODE_80118A4_H
