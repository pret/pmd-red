#ifndef GUARD_DEBUG_H
#define GUARD_DEBUG_H

// size: 0xC
typedef struct DebugLocation
{
    /* 0x0 */ const u8 *file;
    /* 0x4 */ u32 line;
    /* 0x8 */ const u8 *func;
} DebugLocation;

// Macros for easier FatalError handling. FATAL_ERROR should be used as it gets the file, line and function name from gcc, however for matching purposes we always explicitly use FATAL_ERROR_ARGS

#define DEBUG_LOC_PTR(file, line, func)((&((DebugLocation){file, line, func})))

#define FATAL_ERROR_ARGS(file, line, str, ...) FatalError(DEBUG_LOC_PTR(file, line, __func__), str, __VA_ARGS__ )
#define FATAL_ERROR(str, ...) FATAL_ERROR_ARGS(__FILE__, __LINE__, str, __VA_ARGS__)

void FatalError(const DebugLocation *debug, const char *text, ...) NORETURN;
void Log(u8 num, const u8 *text, ...);
void NDS_DebugInit(void);
void nullsub_25(void);
bool8 ScriptLoggingEnabled(bool8);

#endif // GUARD_DEBUG_H
