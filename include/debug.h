#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H

#include "gba/gba.h"

// size: 0xC
typedef struct DebugLocation
{
    /* 0x0 */ u8 *file;
    /* 0x4 */ u32 line;
    /* 0x8 */ u8 *func;
} DebugLocation;

void Log(u8 num, const u8 *text, ...);
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
void PrintFuncFileLine(u8 *buf, const DebugLocation *loc, const u8 *prefix);
void PrintMessageWithFuncFileLine(u8 *buffer, const DebugLocation *debug, const u8 *text, ...);
void sub_8011B08(void);
void sub_8011B88(const u8 *text, ...);
s8 ScriptLoggingEnabled(bool8);
u32 sub_8011BA8(void);
const u8 *sub_8011BAC(void);
void sub_8011B14(void);
u8 sub_8011B20(void);
u8 sub_8011B3C(void);
void sub_8011BC8(u32, u32, u32, ...);
void UnusedHang(void);
void FatalError(const DebugLocation *debug, const char *text, ...) __attribute__((noreturn));

#endif // GUARD_DEBUG_H
