#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"
#include "debug.h"

extern void Hang();

extern bool32 gNDS_DebugEnabled;
extern u8 gUnknown_203B150;

extern const char gUnknown_80D421C[];
extern const char gNotMountText[];
extern const char gNotEntryText[];
extern const char gFuncFileLineString[];
extern const char gFuncFileLineStringWPrefix[];
extern const char gFuncFileLineString2[];

void NDS_DebugInit(void)
{
    nullsub_26();
    nullsub_27();
    nullsub_29();
    nullsub_30();
    nullsub_31();
    nullsub_32();
    nullsub_28();
    gNDS_DebugEnabled = TRUE;
}

void nullsub_25(void)
{
}

void nullsub_26(void)
{
}

// Unused
void PrintFuncFileLineOrNotEntry(char * buf, struct DebugLocation *debug)
{
    if(debug != NULL)
    {
        sprintf(buf, gFuncFileLineString, debug->func, debug->file, debug->line);
    }
    else
    {
        sprintf(buf, gNotEntryText);
    }
}

void PrintFuncFileLine(char *buf, struct DebugLocation *loc, const char* prefix)
{
    sprintf(buf, gFuncFileLineStringWPrefix, prefix, loc->func, loc->file, loc->line);
}

void PrintMessageWithFuncFileLine(u8 *buffer, struct DebugLocation *debug, const char *text, ...)
{
    va_list vArgv;
    u32 length;

    va_start(vArgv, text);
    vsprintf(buffer, text, vArgv);
    length = strlen(buffer);
    sprintf(&buffer[length], gFuncFileLineString2, debug->func, debug->file, debug->line);
    va_end(vArgv);
}

void nullsub_199(void)
{
}

void nullsub_27(void)
{
}

// Unused
void sub_8011B08(void)
{
    gUnknown_203B150 = 1;
}

// Unused
void sub_8011B14(void)
{
    gUnknown_203B150 = 0;
}

// Unused
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

void FatalErrorPrintFuncFileLine(const char *r0, struct DebugLocation *debug)
{
    char buf[0x100];
    if(r0 != NULL){
        PrintFuncFileLine(buf, debug, r0);
    }
    else
    {
        PrintFuncFileLine(buf, debug, gUnknown_80D421C);
    }
}

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
    return gNotMountText;
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
