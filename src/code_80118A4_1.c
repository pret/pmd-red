#include "global.h"

extern u8 gUnknown_203B150;

void PrintFuncFileLine(char *r0, const char *r1, ...);
extern const char gUnknown_80D421C;

void nullsub_199(void)
{
}

void nullsub_27(void)
{
}

void sub_8011B08(void)
{
    gUnknown_203B150 = 1;
}

void sub_8011B14(void)
{
    gUnknown_203B150 = 0;
}

u8 sub_8011B20(void)
{
    gUnknown_203B150 = !gUnknown_203B150;
    return gUnknown_203B150;
}

// unused
u8 sub_8011B3C(void)
{
    return gUnknown_203B150;
}

// unused
void nullsub_137(void)
{

}

// TODO merge with fatal_system
void FatalErrorPrintFuncFileLine(const char *r0, const char *r1)
{
    char buf[0x100];
    if(r0 != 0){
        PrintFuncFileLine(buf, r1, r0);
    }
    else
    {
        PrintFuncFileLine(buf, r1, &gUnknown_80D421C);
    }
}
