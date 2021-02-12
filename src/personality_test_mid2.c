#include "global.h"
#include "personality_test.h"

extern u32 gUnknown_202DF98;
extern void sub_80141B4(const char *r0, u32 r1, u32 r2, u16 r3);
extern void sub_808D8BC(u32 *r0, u32);

extern const char *gPersonalityTypeDescriptionTable[];

void PrintPersonalityTypeDescription(void)
{
  sub_808D8BC(&gUnknown_202DF98,gUnknown_203B400->StarterID);
  sub_80141B4(gPersonalityTypeDescriptionTable[gUnknown_203B400->playerNature],0,
              0,0x101);
}
