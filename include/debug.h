#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H
#include "gba/gba.h"


struct DebugLocation
{
    char *file;
    u32 line;
    char *func;
};

void FatalErrorHang();
void FatalErrorPrintFuncFileLine(const char *r0, struct DebugLocation *debug);
void FatalErrorFormatMessage(const char *text, ...);
void Log(u8 *buffer, const char *text, ...);
void NDS_DebugInit(void);
void nullsub_25(void);
void nullsub_26(void);
void nullsub_27(void);
void nullsub_28(void);
void nullsub_29(void);
void nullsub_30(void);
void nullsub_31(void);
void nullsub_32(void);
void nullsub_137(void);
void nullsub_199(void);
void PrintFuncFileLineOrNotEntry(char * buf, struct DebugLocation *debug);
void PrintFuncFileLine(char *buf, struct DebugLocation *loc, const char* prefix);
void PrintMessageWithFuncFileLine(u8 *buffer, struct DebugLocation *debug, const char *text, ...);
void sub_8011B08(void);
void sub_8011B88(const char *text, ...);
u32 sub_8011BA4(void);
u32 sub_8011BA8(void);
const char *sub_8011BAC(void);
void sub_8011B14(void);
u8 sub_8011B20(void);
u8 sub_8011B3C(void);
void sub_8011BC8(u32 r0, u32 r1, u32 r2, ...);
void UnusedHang(void);
#endif
