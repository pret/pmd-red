// platform/pc/main_game.c — host entry for the full-game binary (pmd-red-game).
//
// Runs the REAL game init path from src/main.c:AgbMain() minus hardware:
//   Pc_MemInit (WAITCNT/DmaStop/mem-init) -> boot register shadows ->
//   InitFileSystem -> archive opens (exercises the generated blob pipeline) ->
//   LoadCharmaps -> InitSprites/Input/BGPalette/WindowBg/Graphics ->
//   60Hz pump (Pc_RequestVBlank/Commit ≈ VBlank_CB) + Pc_VideoPresent.
//
// Skipped (host-owned): sub_800B540 (ISR install), InitFlash (cartridge HW),
// SetInterruptCallback(VBlank_CB) (replaced by Pc_VBlankCommit), GameLoop_Async
// (next milestone; needs save/timing integration).
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <unistd.h>
#ifndef _WIN32
#include <execinfo.h>
#endif

#include "gba/gba.h"
#include "gba_shim.h"
#include "cpu_pc.h"
#include "rom_load.h"
#include "file_system.h"
#include "def_filearchives.h"
#include "text_1.h"
#include "sprite.h"
#include "input.h"
#include "bg_palette_buffer.h"
#include "window_buffer.h"
#include "graphics_memory.h"
#include "main_loops.h"

static void Pc_CrashReport(int sig)
{
    Pc_LogPrintf("=== fatal signal %d ===\n", sig);
    fprintf(stderr, "pmd-red-game: fatal signal %d\n", sig);
    Pc_LogFlush();
    _exit(139);
}

#ifndef _WIN32
static void Pc_CrashAction(int sig, siginfo_t *info, void *ctx)
{
    void *frames[32];
    int n = backtrace(frames, 32);
    char **syms;
    int i;
    (void)ctx;
    Pc_LogPrintf("=== fatal signal %d at %p ===\n", sig,
                 info != NULL ? info->si_addr : NULL);
    syms = backtrace_symbols(frames, n);
    if (syms != NULL) {
        for (i = 0; i < n; i++)
            Pc_LogPrintf("  %s\n", syms[i]);
        free(syms);
    }
    fprintf(stderr, "pmd-red-game: fatal signal %d at %p\n", sig,
            info != NULL ? info->si_addr : NULL);
    backtrace_symbols_fd(frames, n, 2);
    Pc_LogFlush();
    _exit(139);
}
#endif

static void Pc_ApplyBootShadows(void) {
    // Same values as src/main.c:65-78 so game code sees identical state.
    gPcRegs.WIN0H = 0;
    gPcRegs.WIN1H = 0;
    gPcRegs.WIN0V = 0;
    gPcRegs.WIN1V = 0;
    gPcRegs.WININ = WININ_WIN0_ALL | WININ_WIN1_ALL;
    gPcRegs.WINOUT = WINOUT_WIN01_BG0 | WINOUT_WIN01_BG2 | WINOUT_WIN01_BG3 | WINOUT_WIN01_OBJ | WINOUT_WIN01_CLR;
    gPcRegs.BLDCNT = BLDCNT_TGT1_BG1 | BLDCNT_EFFECT_BLEND | BLDCNT_TGT2_BG2 | BLDCNT_TGT2_BG3 | BLDCNT_TGT2_BD | BLDCNT_TGT2_OBJ;
    gPcRegs.BLDALPHA = BLDALPHA_BLEND(10, 6);
    gPcRegs.BG0CNT = BGCNT_PRIORITY(0) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(12);
    gPcRegs.BG1CNT = BGCNT_PRIORITY(1) | BGCNT_CHARBASE(0) | BGCNT_WRAP | BGCNT_SCREENBASE(13);
    gPcRegs.BG2CNT = BGCNT_PRIORITY(2) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(14);
    gPcRegs.BG3CNT = BGCNT_PRIORITY(3) | BGCNT_CHARBASE(2) | BGCNT_WRAP | BGCNT_SCREENBASE(15);
    gPcRegs.DISPCNT = DISPCNT_WIN1_ON | DISPCNT_WIN0_ON | DISPCNT_OBJ_ON | DISPCNT_BG_ALL_ON | DISPCNT_OBJ_1D_MAP;
}

static void Pc_CheckArchive(const char *label, const FileArchive *arc, const char *probe)
{
    OpenedFile *f = OpenFileAndGetFileDataPtr((const u8 *)probe, arc);
    printf("boot: archive %-8s count=%-4d probe '%s' -> %s (%p)\n",
           label, arc->count, probe, f != NULL ? "found" : "MISS",
           f != NULL ? (const void *)f->data : NULL);
}

int main(int argc, char **argv) {
    int scale = 3, frames = 0, i, autoStart = -1;
    int console = 1; // console on by default; --noconsole routes to client.log only
    const char *dump = NULL;
    const char *autoSpec = NULL;
    const char *logFile = NULL;
    char exeDir[1024 + 1];
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--scale") == 0 && i + 1 < argc)
            scale = atoi(argv[++i]);
        else if (strcmp(argv[i], "--frames") == 0 && i + 1 < argc)
            frames = atoi(argv[++i]);
        else if (strcmp(argv[i], "--dump") == 0 && i + 1 < argc)
            dump = argv[++i];
        else if (strcmp(argv[i], "--autopress") == 0 && i + 1 < argc)
            autoSpec = argv[++i];
        else if (strcmp(argv[i], "--console") == 0)
            console = 1;
        else if (strcmp(argv[i], "--noconsole") == 0)
            console = 0;
        else if (strcmp(argv[i], "--log") == 0 && i + 1 < argc)
            logFile = argv[++i];
    }

    // --autopress KEY@START holds a key from the given paced-vblank frame
    // (e.g. "A@250") so CI can select menu items / advance text without a
    // real keyboard.
    {
        u16 autoKeys = 0;
        char keyName[16];
        if (autoSpec != NULL && sscanf(autoSpec, "%15[^@]@%d", keyName, &autoStart) == 2) {
            if (strcasecmp(keyName, "A") == 0) autoKeys = A_BUTTON;
            else if (strcasecmp(keyName, "B") == 0) autoKeys = B_BUTTON;
            else if (strcasecmp(keyName, "START") == 0) autoKeys = START_BUTTON;
            else if (strcasecmp(keyName, "SELECT") == 0) autoKeys = SELECT_BUTTON;
            else if (strcasecmp(keyName, "RIGHT") == 0) autoKeys = DPAD_RIGHT;
            else if (strcasecmp(keyName, "LEFT") == 0) autoKeys = DPAD_LEFT;
            else if (strcasecmp(keyName, "UP") == 0) autoKeys = DPAD_UP;
            else if (strcasecmp(keyName, "DOWN") == 0) autoKeys = DPAD_DOWN;
            else if (strcasecmp(keyName, "L") == 0) autoKeys = L_BUTTON;
            else if (strcasecmp(keyName, "R") == 0) autoKeys = R_BUTTON;
        }
        if (autoKeys)
            Pc_SetAutopress(autoStart, 60 * 60, autoKeys);
    }

    Pc_MemInit();
    Pc_ApplyBootShadows();
    Pc_ExeDir(exeDir, sizeof(exeDir), argv[0]);
    Pc_LogOpen(exeDir, console, logFile); // stdout/stderr -> client.log (--console dev flag)
    Pc_InstallCrashHandler();
#ifndef _WIN32
    {
        struct sigaction sa;
        memset(&sa, 0, sizeof(sa));
        sa.sa_sigaction = Pc_CrashAction;
        sa.sa_flags = SA_SIGINFO;
        sigaction(SIGSEGV, &sa, NULL);
        sigaction(SIGABRT, &sa, NULL);
        sigaction(SIGBUS, &sa, NULL);
    }
#endif
    Pc_VideoInit(scale);
    Pc_InputInit();
    Pc_AudioInit();
    Pc_SaveInit(NULL);
    // baserom.gba is required next to the executable: no ROM dump, no game.
    // Fail hard (log + dialog) instead of running with blank blob data.
    if (Pc_RomLoad(exeDir) != 0) {
        Pc_FatalMessage("baserom.gba was not found next to the executable.\n"
                        "\n"
                        "Place your Pokemon Mystery Dungeon: Red Rescue Team ROM\n"
                        "(baserom.gba, sha1 9f4cfc5b5f4859d17169a485462e977c7aac2b89)\n"
                        "in the same folder as this program and run it again.");
        Pc_LogClose("fatal: baserom.gba not found");
        return 1;
    }
    Pc_SetupRomAddressSpace();

    // Real game init (AgbMain order, host-safe subset).
    printf("boot: InitFileSystem\n");
    InitFileSystem();
    Pc_CheckArchive("dungeon", &gDungeonFileArchive, "itempat");
    Pc_CheckArchive("system", &gSystemFileArchive, "kanji_a");
    Pc_CheckArchive("system", &gSystemFileArchive, "wazapara");
    printf("boot: LoadCharmaps\n");
    LoadCharmaps();
    printf("boot: InitSprites\n");
    InitSprites();
    printf("boot: InitInput\n");
    InitInput();
    printf("boot: InitBGPaletteBuffer\n");
    InitBGPaletteBuffer();
    printf("boot: WindowBgBufferInit\n");
    WindowBgBufferInit();
    printf("boot: InitGraphics\n");
    InitGraphics();
    printf("boot: init complete\n");

    // GameLoop_Async() prefix: heap, params, save probe, script inits.
    Pc_GameBootStage();

    // Full title -> interactive main menu -> real game flow with render,
    // ~60Hz pacing and input sampling handled at the VBlankIntrWait boundary
    // (boot-stage script demos above run unpaced so they finish fast).
    // --frames caps total rendered frames (mostly for CI); 0 runs until the
    // window is closed or Esc is pressed.
    Pc_SetPaced(1);
    printf("boot: entering title/game driver (%s)\n", frames > 0 ? "bounded" : "unbounded");
    Pc_RunTitleAndGame(frames);

    if (dump != NULL)
        Pc_VideoDumpPPM(dump);
    Pc_SaveFlush();

    printf("pmd-red-game: %u frame(s), DISPCNT=0x%04X BLDCNT=0x%04X\n",
           Pc_VBlankFrameCount(), gPcRegs.DISPCNT, gPcRegs.BLDCNT);

    Pc_AudioShutdown();
    Pc_InputShutdown();
    Pc_VideoShutdown();

    if (Pc_QuitRequested())
        Pc_LogClose("user quit (window close / Esc)");
    else if (frames > 0)
        Pc_LogClose("bounded frames run complete");
    else
        Pc_LogClose("clean exit");
    return 0;
}
