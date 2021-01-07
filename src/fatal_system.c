#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"

extern const char gNotMountText;
extern void Hang();

void FatalErrorFormatMessage(const char *text, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(bufPrint, text, vArgv);
    va_end(vArgv);
}


void sub_8011B88(const char *text, ...)
{
    char bufPrint[0x100];
    va_list vArgv;
    va_start(vArgv, text);
    vsprintf(bufPrint, text, vArgv);
    va_end(vArgv);
}

void nullsub_28(void)
{
}

u32 sub_8011BA4(void)
{
    return 0;
}

// Unused
u32 sub_8011BA8(void)
{
    return 0;
}

// Unused
const char *sub_8011BAC(void)
{
    return &gNotMountText;
}

// Unused
void UnusedHang(void)
{
    Hang();
}
