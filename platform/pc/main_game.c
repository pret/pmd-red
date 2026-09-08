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

static void Pc_CrashReport(int sig)
{
#ifndef _WIN32
    void *frames[32];
    int n = backtrace(frames, 32);
    fprintf(stderr, "pmd-red-game: fatal signal %d\n", sig);
    backtrace_symbols_fd(frames, n, 2);
#else
    fprintf(stderr, "pmd-red-game: fatal signal %d\n", sig);
#endif
    _exit(139);
}

#ifndef _WIN32
static void Pc_CrashAction(int sig, siginfo_t *info, void *ctx)
{
    void *frames[32];
    int n = backtrace(frames, 32);
    (void)ctx;
    fprintf(stderr, "pmd-red-game: fatal signal %d at %p\n", sig,
            info != NULL ? info->si_addr : NULL);
    backtrace_symbols_fd(frames, n, 2);
    _exit(139);
}
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
    int scale = 3, frames = 0, i;
    const char *dump = NULL;
    const char *romPath = NULL;
    for (i = 1; i < argc; i++) {
        if (strcmp(argv[i], "--scale") == 0 && i + 1 < argc)
            scale = atoi(argv[++i]);
        else if (strcmp(argv[i], "--frames") == 0 && i + 1 < argc)
            frames = atoi(argv[++i]);
        else if (strcmp(argv[i], "--dump") == 0 && i + 1 < argc)
            dump = argv[++i];
        else if (strcmp(argv[i], "--rom") == 0 && i + 1 < argc)
            romPath = argv[++i];
    }

    Pc_MemInit();
    Pc_ApplyBootShadows();
    setvbuf(stdout, NULL, _IONBF, 0); // crash-debuggable boot log
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
    // Fill the baserom-extracted blob arrays from the user's ROM dump, then
    // mirror every blob into the GBA ROM window so baked 0x08 addresses work.
    if (Pc_RomLoad(romPath) != 0) {
        printf("boot: WARNING no baserom.gba loaded; title/ROM blob data will be blank\n");
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

    // Title flow: setup, fade, save read, BGM, bounded menu pump.
    Pc_TitleSmoke(30);

    // Main loop: unbounded by default (runs until the window is closed or Esc is
    // pressed). --frames N keeps a bounded/headless mode for CI and screenshots.
    printf("boot: entering main loop (%s)\n", frames > 0 ? "bounded" : "unbounded");
    for (i = 0; frames <= 0 || i < frames; i++) {
        Pc_InputPump();
        Pc_RequestVBlank();
        Pc_VBlankCommit();
        Pc_AudioFrame();
        Pc_FrameActions();   // real GBA frame pump (replaces VBlank_CB tail)
        Pc_VideoPresent();
        if (frames <= 0 && Pc_QuitRequested())
            break;
    }
    if (dump != NULL)
        Pc_VideoDumpPPM(dump);
    Pc_SaveFlush();

    printf("pmd-red-game: %d frame(s), DISPCNT=0x%04X BLDCNT=0x%04X\n", frames, gPcRegs.DISPCNT, gPcRegs.BLDCNT);

    Pc_AudioShutdown();
    Pc_InputShutdown();
    Pc_VideoShutdown();
    return 0;
}
