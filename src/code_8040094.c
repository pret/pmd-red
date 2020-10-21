#include "global.h"

extern u8 *gUnknown_203B418;
extern u32 gUnknown_203B47C;

extern void sub_803F7BC(void);
extern void sub_80060EC(void);
extern void sub_8094FB4(u32);
extern void sub_800CB20(void);
extern void sub_800485C(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_8083F58(void);
extern void sub_8011860(void);

void sub_8040094(u8 r0)
{
    gUnknown_203B418[0x18217] = r0;
    sub_803F7BC();
    sub_80060EC();
    sub_8094FB4(gUnknown_203B47C);
    sub_800CB20();
    sub_800485C();
    xxx_call_update_bg_sound_input();
    sub_8083F58();
    sub_8011860();
}
