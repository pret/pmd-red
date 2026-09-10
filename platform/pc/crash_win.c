// platform/pc/crash_win.c — crash diagnostics + client.log + exe-dir lookup (per-platform).
//
// Kept out of main_game.c so game headers never share a TU with <windows.h>
// (OpenFile etc. collide with the game's own symbols). On Windows we install
// an unhandled-exception filter that prints the faulting address so builds
// are debuggable with addr2line; elsewhere the POSIX sigaction path in
// main_game.c is used instead.
//
// client.log policy: the file is (re)generated next to the executable on every
// launch so that no matter how the process ends — window close, a fatal
// signal, or an SEH exception — there is always a log describing the last
// session. An existing client.log is rotated to client-prev.log first.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <stdarg.h>
#include <stdint.h>

#ifdef _WIN32
#include <windows.h>
#include <direct.h>
#include <io.h>
#include <fcntl.h>
#define Pc_Getcwd _getcwd
#else
#include <unistd.h>
#include <limits.h>
#include <fcntl.h>
#define Pc_Getcwd getcwd
#endif

#ifdef __APPLE__
#include <mach-o/dyld.h>
#endif

// ---- client.log ----
//
// By default stdout/stderr are the log (so every game printf lands in the
// file). With --console, stdout/stderr go to a console instead, but the file
// is still opened so lifecycle/crash records are always captured.
static FILE *sLogFile = NULL;
static char sLogPath[1024 + 1] = "";

static int Pc_IsAbsolute(const char *p)
{
    return p[0] == '/' || p[0] == '\\' ||
           (p[0] != '\0' && p[1] == ':' && (p[2] == '/' || p[2] == '\\'));
}

// Directory containing the running executable, with a trailing separator.
// argv0 is a fallback for platforms without /proc/self/exe.
void Pc_ExeDir(char *out, size_t cap, const char *argv0)
{
    char path[1024 + 1];
    char *slash;

    if (out == NULL || cap == 0)
        return;
    out[0] = '\0';
    path[0] = '\0';

#ifdef _WIN32
    {
        int n = GetModuleFileNameA(NULL, path, sizeof(path) - 1);
        if (n > 0)
            path[n] = '\0';
    }
#elif defined(__linux__)
    {
        int n = (int)readlink("/proc/self/exe", path, sizeof(path) - 1);
        if (n > 0)
            path[n] = '\0';
    }
#elif defined(__APPLE__)
    {
        uint32_t size = (uint32_t)sizeof(path);
        if (_NSGetExecutablePath(path, &size) == 0) {
            char *rp = realpath(path, NULL);
            if (rp != NULL) {
                snprintf(path, sizeof(path), "%s", rp);
                free(rp);
            }
        }
    }
#endif

    if (path[0] == '\0' && argv0 != NULL && argv0[0] != '\0') {
        snprintf(path, sizeof(path), "%s", argv0);
        if (!Pc_IsAbsolute(path)) {
            char cwd[1024 + 1];
            if (Pc_Getcwd(cwd, sizeof(cwd)) != NULL) {
                char tmp[2048 + 1];
                snprintf(tmp, sizeof(tmp), "%s/%s", cwd, path);
                snprintf(path, sizeof(path), "%s", tmp);
            }
        }
    }

    if (path[0] == '\0') {
        snprintf(out, cap, "./");
        return;
    }

    slash = strrchr(path, '/');
    if (slash == NULL)
        slash = strrchr(path, '\\');
    if (slash != NULL)
        *slash = '\0';

    if (path[0] == '\0')
        snprintf(out, cap, "./");
    else
        snprintf(out, cap, "%s/", path);
}

static const char *Pc_LogTimestamp(void)
{
    static char buf[32];
    time_t now = time(NULL);
    struct tm *lt = localtime(&now);
    if (lt == NULL) {
        snprintf(buf, sizeof(buf), "?");
        return buf;
    }
    strftime(buf, sizeof(buf), "%Y-%m-%d %H:%M:%S", lt);
    return buf;
}

int Pc_LogPrintf(const char *fmt, ...)
{
    va_list ap;
    int r;

    if (sLogFile == NULL)
        sLogFile = stderr;
    va_start(ap, fmt);
    r = vfprintf(sLogFile, fmt, ap);
    va_end(ap);
    fflush(sLogFile);
    return r;
}

void Pc_LogFlush(void)
{
    if (sLogFile != NULL)
        fflush(sLogFile);
}

void Pc_LogClose(const char *reason)
{
    if (reason != NULL && reason[0] != '\0')
        Pc_LogPrintf("=== session end (%s) %s ===\n", reason, Pc_LogTimestamp());
    Pc_LogFlush();
    if (sLogFile != NULL && sLogFile != stdout && sLogFile != stderr)
        fclose(sLogFile);
    sLogFile = NULL;
}

void Pc_LogOpen(const char *exeDir, int wantConsole, const char *logFile)
{
    int rotate = (logFile == NULL || logFile[0] == '\0');

    if (logFile != NULL && logFile[0] != '\0') {
        snprintf(sLogPath, sizeof(sLogPath), "%s", logFile);
    } else if (exeDir != NULL && exeDir[0] != '\0') {
        snprintf(sLogPath, sizeof(sLogPath), "%sclient.log", exeDir);
    } else {
        snprintf(sLogPath, sizeof(sLogPath), "client.log");
    }

    // Rotate an existing client.log to client-prev.log (dropping the stale
    // one) so client.log always reflects the latest session.
    if (rotate && exeDir != NULL && exeDir[0] != '\0') {
        char prevPath[1024 + 1];
        snprintf(prevPath, sizeof(prevPath), "%sclient-prev.log", exeDir);
        remove(prevPath);
        rename(sLogPath, prevPath);
    }

    if (wantConsole) {
        AllocConsole();
        freopen("CONOUT$", "w", stdout);
        freopen("CONOUT$", "w", stderr);
        sLogFile = fopen(sLogPath, "a"); // still produce client.log for lifecycle/crash
    } else {
        // Route stdout AND stderr through ONE open file description so the two
        // streams share a single file offset (freopen'ing the same path twice
        // would let the first writer clobber the other's bytes).
        int fd;
#ifdef _WIN32
        fd = _open(sLogPath, _O_WRONLY | _O_CREAT | _O_TRUNC | _O_BINARY, 0644);
#else
        fd = open(sLogPath, O_WRONLY | O_CREAT | O_TRUNC, 0644);
#endif
        if (fd >= 0) {
#ifdef _WIN32
            _dup2(fd, _fileno(stdout));
            _dup2(fd, _fileno(stderr));
#else
            dup2(fd, STDOUT_FILENO);
            dup2(fd, STDERR_FILENO);
#endif
            close(fd);
        }
        sLogFile = stderr; // lifecycle/crash share the client.log sink
    }

    setvbuf(stdout, NULL, _IONBF, 0);
    setvbuf(stderr, NULL, _IONBF, 0);
    if (sLogFile != NULL)
        setvbuf(sLogFile, NULL, _IONBF, 0);

    Pc_LogPrintf("=== pmd-red-game session start %s ===\n", Pc_LogTimestamp());
}

// Show a fatal error to the user (native message box on Windows, stderr
// otherwise) and record it in client.log. Keeps <windows.h> out of game TUs.
// PMD_RED_NO_DIALOG=1 suppresses the box for CI/headless runs.
void Pc_FatalMessage(const char *msg)
{
    const char *noDialog = getenv("PMD_RED_NO_DIALOG");
    Pc_LogPrintf("FATAL: %s\n", msg);
    Pc_LogFlush();
#ifdef _WIN32
    if (noDialog == NULL || noDialog[0] == '\0')
        MessageBoxA(NULL, msg, "pmd-red-game",
                    MB_OK | MB_ICONERROR | MB_SETFOREGROUND);
#else
    fprintf(stderr, "FATAL: %s\n", msg);
#endif
}

#ifdef _WIN32

static LONG WINAPI Pc_WinException(PEXCEPTION_POINTERS ep)
{
    ULONG_PTR ip = 0;
#ifdef _M_X64
    ip = ep->ContextRecord->Rip;
#else
    ip = ep->ContextRecord->Eip;
#endif
    Pc_LogPrintf("=== unhandled exception 0x%08lX at %p (image base %p) ===\n",
                 (unsigned long)ep->ExceptionRecord->ExceptionCode,
                 (void *)ip, (void *)GetModuleHandleA(NULL));
    if (ep->ExceptionRecord->ExceptionCode == EXCEPTION_ACCESS_VIOLATION) {
        Pc_LogPrintf("faulting access: %p\n",
                     (void *)ep->ExceptionRecord->ExceptionInformation[1]);
    }
#if defined(_M_IX86)
    Pc_LogPrintf("regs eax=%08lX ebx=%08lX ecx=%08lX edx=%08lX esi=%08lX edi=%08lX ebp=%08lX esp=%08lX\n",
                 (unsigned long)ep->ContextRecord->Eax,
                 (unsigned long)ep->ContextRecord->Ebx,
                 (unsigned long)ep->ContextRecord->Ecx,
                 (unsigned long)ep->ContextRecord->Edx,
                 (unsigned long)ep->ContextRecord->Esi,
                 (unsigned long)ep->ContextRecord->Edi,
                 (unsigned long)ep->ContextRecord->Ebp,
                 (unsigned long)ep->ContextRecord->Esp);
#elif defined(_M_X64)
    Pc_LogPrintf("regs rax=%016llX rbx=%016llX rcx=%016llX rdx=%016llX rsi=%016llX rdi=%016llX rbp=%016llX rsp=%016llX\n",
                 (unsigned long long)ep->ContextRecord->Rax,
                 (unsigned long long)ep->ContextRecord->Rbx,
                 (unsigned long long)ep->ContextRecord->Rcx,
                 (unsigned long long)ep->ContextRecord->Rdx,
                 (unsigned long long)ep->ContextRecord->Rsi,
                 (unsigned long long)ep->ContextRecord->Rdi,
                 (unsigned long long)ep->ContextRecord->Rbp,
                 (unsigned long long)ep->ContextRecord->Rsp);
#endif
    if (sLogFile != stderr) {
        fprintf(stderr, "pmd-red-game: unhandled exception 0x%08lX at %p (image base %p)\n",
                (unsigned long)ep->ExceptionRecord->ExceptionCode,
                (void *)ip, (void *)GetModuleHandleA(NULL));
    }
    Pc_LogFlush();
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