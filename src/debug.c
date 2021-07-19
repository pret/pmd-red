#include <stdarg.h>
#include <stdio.h>
#include "gba/gba.h"
#include "config.h"
#include "debug.h"

extern void Hang();
static void FatalErrorHang(void) __attribute__((noreturn));

extern bool32 gNDS_DebugEnabled;
extern u8 gUnknown_203B150;

ALIGNED(4) const char gFuncFileLineString[] = _("func = '%s'\n"
                                                "file = '%s'  line = %5d");

ALIGNED(4) const char gNotEntryText[] = _("--- not entry ---");
ALIGNED(4) const char gFuncFileLineStringWPrefix[] = _("%sfunc = '%s'\n"
                                                       "file = '%s'  line = %5d\n");

ALIGNED(4) const char gFuncFileLineString2[] = _("func = '%s'\n"
                                                 "file = '%s'  line = %5d\n");

ALIGNED(4) const char debug_fill14[] = _("pksdir0");
ALIGNED(4) const char gDebugPrintPrefix[] = _("  Print  ");
ALIGNED(4) const char debug_fill13[] = _("pksdir0");

ALIGNED(4) const char Performance_Text[] = _("Performance");
ALIGNED(4) const char MemoryCard_Text[] = _("Memory Card");
ALIGNED(4) const char Memory_Text[] = _("Memory");
ALIGNED(4) const char Flag_Text[] = _("Flag");
ALIGNED(4) const char Se_Text[] = _("Se");
ALIGNED(4) const char Bgm_Text[] = _("Bgm");
ALIGNED(4) const char Sound_Text[] = _("Sound");
ALIGNED(4) const char Dungeon_Text[] = _("Dungeon");
ALIGNED(4) const char GroundScript_Text[] = _("GroundScript");
ALIGNED(4) const char Ground_Text[] = _("Ground");


ALIGNED(4) const char gNotMountText[] = _("not mount log system");
ALIGNED(4) const char debug_fill9[] = _("pksdir0");
ALIGNED(4) const char debug_fill10[] = _("pksdir0");
ALIGNED(4) const char debug_fill11[] = _("pksdir0");
ALIGNED(4) const char debug_fill12[] = _("pksdir0");

ALIGNED(4) const char gFatalText[] = _("!!!!! Fatal !!!!!\n");
ALIGNED(4) const char gFatalErrorBufferPlaceholder[] = _("%s\n");

ALIGNED(4) const char debug_fill0[] = _("pksdir0");
ALIGNED(4) const char debug_fill1[] = _("pksdir0");
ALIGNED(4) const char debug_fill2[] = _("pksdir0");
ALIGNED(4) const char debug_fill3[] = _("pksdir0");
ALIGNED(4) const char debug_fill4[] = _("pksdir0");
ALIGNED(4) const char debug_fill5[] = _("pksdir0");
ALIGNED(4) const char debug_fill6[] = _("pksdir0");
ALIGNED(4) const char debug_fill7[] = _("pksdir0");
ALIGNED(4) const char debug_fill8[] = _("pksdir0");

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

static void FatalErrorPrintFuncFileLine(const char *prefix, struct DebugLocation *debug)
{
    char buf[0x100];
    if(prefix != NULL){
        PrintFuncFileLine(buf, debug, prefix);
    }
    else
    {
        PrintFuncFileLine(buf, debug, gDebugPrintPrefix);
    }
}

static void FatalErrorFormatMessage(const char *text, ...)
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
const char *GetNotMountText(void)
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

static void FatalErrorHang()
{
    Hang();
}

void FatalError(struct DebugLocation *debug, const char *text, ...) 
{
    char buf[0x100];
    va_list vArgv;

    FatalErrorPrintFuncFileLine(gFatalText, debug);
    va_start(vArgv, text);
    vsprintf(buf, text, vArgv);
    va_end(vArgv);
    FatalErrorFormatMessage(gFatalErrorBufferPlaceholder, buf);
    FatalErrorHang();
}
