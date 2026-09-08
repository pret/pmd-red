// platform/pc/crash_win.c — best-effort crash diagnostics (per-platform).
//
// Kept out of main_game.c so game headers never share a TU with <windows.h>
// (OpenFile etc. collide with the game's own symbols). On Windows we install
// an unhandled-exception filter that prints the faulting address so builds
// are debuggable with addr2line; elsewhere the POSIX sigaction path in
// main_game.c is used instead.
#include <stdio.h>

#ifdef _WIN32
#include <windows.h>

// Attach a console (or redirect to a log file) so the -mwindows exe shows its
// stdout/stderr when launched by double-click. Call after setvbuf in main.
void Pc_ConsoleOpen(const char *logFile, int wantConsole)
{
    if (wantConsole) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        return;
    }
    if (logFile != NULL && logFile[0] != '\0') {
        freopen(logFile, "w", stdout);
        freopen(logFile, "a", stderr);
    }
}

static LONG WINAPI Pc_WinException(PEXCEPTION_POINTERS ep)
{
    ULONG_PTR ip = 0;
#ifdef _M_X64
    ip = ep->ContextRecord->Rip;
#else
    ip = ep->ContextRecord->Eip;
#endif
    fprintf(stderr, "pmd-red-game: unhandled exception 0x%08lX at %p (image base %p)\n",
            (unsigned long)ep->ExceptionRecord->ExceptionCode,
            (void *)ip, (void *)GetModuleHandleA(NULL));
    fflush(stderr);
    return EXCEPTION_CONTINUE_SEARCH;
}

void Pc_InstallCrashHandler(void)
{
    SetUnhandledExceptionFilter(Pc_WinException);
}
#else
void Pc_InstallCrashHandler(void)
{
    // POSIX: main_game.c installs its own sigaction-based handler.
}
#endif