#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H

// size: 0xC
typedef struct DebugLocation
{
    /* 0x0 */ const u8 *file;
    /* 0x4 */ u32 line;
    /* 0x8 */ const u8 *func;
} DebugLocation;

void FatalError(const DebugLocation *debug, const char *text, ...) NORETURN;
void Log(u8 num, const u8 *text, ...);
void NDS_DebugInit(void);
void nullsub_25(void);
bool8 ScriptLoggingEnabled(bool8);

#endif // GUARD_DEBUG_H
