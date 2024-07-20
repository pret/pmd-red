#include "global.h"
#include "code_8010EF0.h"

extern struct UnkBgStruct *gUnknown_203B0E4;

extern void CloseFile(OpenedFile *);

void sub_8010EF0(void)
{
    CloseFile(gUnknown_203B0E4->unk0[4]);
    CloseFile(gUnknown_203B0E4->unk0[2]);
    CloseFile(gUnknown_203B0E4->unk0[3]);
    CloseFile(gUnknown_203B0E4->unk0[0]);
    CloseFile(gUnknown_203B0E4->unk0[1]);
}
