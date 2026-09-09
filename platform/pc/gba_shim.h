// platform/pc/gba_shim.h — PC backend declarations (host builds only).
//
// The GBA headers themselves branch on PLATFORM_PC now (see include/gba/
// defines.h, io_reg.h, macro.h), so this header only declares the C functions
// the PC backends provide: BIOS syscall replacements + video/input/audio/save.
//
// Compile game sources with -DPLATFORM_PC; no -include flag needed.
#ifndef PMDRED_PC_GBA_SHIM_H
#define PMDRED_PC_GBA_SHIM_H

#include <stddef.h>

#ifdef PLATFORM_PC

// ---- Crash diagnostics + client.log (crash_win.c) ----
void Pc_InstallCrashHandler(void);
void Pc_ExeDir(char *out, size_t cap, const char *argv0); // dir of running exe, trailing sep
void Pc_LogOpen(const char *exeDir, int wantConsole, const char *logFile); // client.log sink
int Pc_LogPrintf(const char *fmt, ...); // lifecycle/crash record, always flushed
void Pc_LogFlush(void);
void Pc_LogClose(const char *reason); // final "session end" line + close
void Pc_FatalMessage(const char *msg); // log + native error dialog

// ---- BIOS syscall replacements (cpu_pc.c) ----
// Signatures match libagbsyscall so game call sites need no edits.
void Pc_MemInit(void);       // zero VRAM/PLTT/OAM + regs, KEYINPUT idle
void Pc_VBlankCommit(void);  // PC replacement for the VBlank_CB register reloads
void Pc_RequestVBlank(void); // set by the host 60Hz loop; consumed by VBlankIntrWait
void Pc_SetPaced(int on);    // enable 60Hz render/pacing inside VBlankIntrWait
unsigned int Pc_VBlankFrameCount(void); // frames rendered via VBlankIntrWait

// ---- Video backend (video_pc.c) ----
void Pc_VideoInit(int scale);      // init framebuffer/window (SDL if HAVE_SDL2)
void Pc_VideoPresent(void);        // composite shadows -> screen, 240x160 scaled
void Pc_VideoShutdown(void);
void Pc_VideoDumpPPM(const char *path); // headless framebuffer dump (no SDL needed)

// ---- Input backend (input_pc.c) ----
void Pc_InputInit(void);
void Pc_InputPump(void); // refresh REG_KEYINPUT shadow (active-low, KEYS_MASK idle)
void Pc_InputShutdown(void);
int Pc_QuitRequested(void); // true when window close / Esc / quit requested
void Pc_SetAutopress(int startFrame, int durFrames, u16 keys); // scripted key hold (CI)

// ---- Audio backend (audio_pc.c, mute-first) ----
void Pc_AudioInit(void);
void Pc_AudioFrame(void); // called once per 60Hz tick; noop until sequencer lands
void Pc_AudioShutdown(void);

// ---- Save backend (save_pc.c) ----
void Pc_SaveInit(const char *dir); // host save dir (default: exe dir / cwd)
void Pc_SaveFlush(void);
int Pc_SaveRead(s32 sector, u8 *dest, s32 size);      // read flash sector range
int Pc_SaveWrite(s32 sector, u8 *src, s32 size);      // erase+write flash sector range
int Pc_SaveEraseChip(void);                           // reset image to all-0xFF

#endif // PLATFORM_PC
#endif // PMDRED_PC_GBA_SHIM_H
