#include "global.h"

struct unkTimeStruct
{
    u16 unk0;
    u8 unk2;
    u8 unk3;
    u8 unk4;
};

extern struct unkTimeStruct *gUnknown_203B47C;
extern struct unkTimeStruct gPlayTime;

// Forward Declaration
void sub_8094FA8(struct unkTimeStruct *Time);


void sub_8094F88(void)
{
    gUnknown_203B47C = &gPlayTime;
    sub_8094FA8(&gPlayTime);
}

struct unkTimeStruct *sub_8094FA0(void)
{
    return &gPlayTime;
}

void sub_8094FA8(struct unkTimeStruct *Time)
{
    Time->unk4 = 0;
    Time->unk3 = 0;
    Time->unk2 = 0;
    Time->unk0 = 0;
}
