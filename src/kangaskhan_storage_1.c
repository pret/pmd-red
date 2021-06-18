#include "global.h"
#include "file_system.h"
#include "pokemon.h"
#include "input.h"
#include "kangaskhan_storage.h"

extern struct unkStruct_203B208 *gUnknown_203B208;

extern u8 gUnknown_80DB7A8;

extern void xxx_call_draw_string(u32 x, u32 y, u8 *, u32, u32);
extern void sub_801CCD8();
extern void sub_801AD34(u32);
extern void sub_8012EA4(u32 *, u32);
extern void sub_8008C54(u32);
extern void sub_80073B8(u32);
extern void sub_8013C68(u32 *);
extern void sub_80073E0(u32);

void sub_8017598(void)
{
  
  sub_8008C54(gUnknown_203B208->unkBC);
  sub_80073B8(gUnknown_203B208->unkBC);
  xxx_call_draw_string(4,0,&gUnknown_80DB7A8,gUnknown_203B208->unkBC,0); // Number?
  sub_8013C68(&gUnknown_203B208->unkA8);
  sub_80073E0(gUnknown_203B208->unkBC);
  sub_801CCD8();
  sub_801AD34(0);
  sub_8012EA4(&gUnknown_203B208->unk58,0);
}
