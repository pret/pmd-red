#include "global.h"
#include "time.h"
#include "file_system.h"

struct unkStruct_203B418
{
    u8 padding[0x181FB];
    u32 unk181FC;
    u32 unk18200;
    u32 unk18204;
    u32 unk18208;
    u32 unk1820C;
    u32 unk18210;
    u8 padding2[3];
    u8 unk18217;
};

extern struct PlayTimeStruct *gUnknown_203B47C;
extern struct unkStruct_203B418 *gUnknown_203B418;
extern s32 gUnknown_80F6568[];
extern u8 gUnknown_202EE01;
extern const char gUnknown_80F6604; // "zmappat"
extern struct FileArchive gUnknown_83B0000;
extern struct OpenedFile *gUnknown_202EE04;

extern void sub_803F7BC(void);
extern void sub_80060EC(void);
extern void sub_800CB20(void);
extern void LoadBufferedInputs(void);
extern void xxx_call_update_bg_sound_input(void);
extern void sub_8083F58(void);
extern void sub_8011860(void);

void sub_8040094(u8 r0)
{
    gUnknown_203B418->unk18217 = r0;
    sub_803F7BC();
    sub_80060EC();
    IncrementPlayTime(gUnknown_203B47C);
    sub_800CB20();
    LoadBufferedInputs();
    xxx_call_update_bg_sound_input();
    sub_8083F58();
    sub_8011860();
}

void sub_80400D4(void)
{
    s32 temp;
    temp = gUnknown_203B418->unk18200;
    if(temp == 0)
        return;
    if(temp > 0x1E)
        temp = 0x1F;
    gUnknown_203B418->unk181FC = gUnknown_80F6568[temp];
    gUnknown_203B418->unk18200--;
    if(gUnknown_203B418->unk18200 == 0)
        gUnknown_203B418->unk18200 = gUnknown_203B418->unk18204;
}

void sub_8040124(void)
{
    gUnknown_202EE01 = 0;
}

void sub_8040130(void)
{
    gUnknown_202EE04 = OpenFileAndGetFileDataPtr(&gUnknown_80F6604, &gUnknown_83B0000);
}
