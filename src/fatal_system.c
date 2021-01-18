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

void Log(u8 *buffer, const char *text, ...)
{
    va_list vArgv;
    va_start(vArgv, text);
    va_end(vArgv);
}

// Unused
void sub_8011BC8(u32 r0, u32 r1, u32 r2, ...)
{
    va_list vArgv;
    va_start(vArgv, r2);
    va_end(vArgv);
}

void nullsub_29()
{
}

void nullsub_30()
{
}

void nullsub_31()
{
}

void nullsub_32()
{
}

void FatalErrorHang()
{
    Hang();
}
