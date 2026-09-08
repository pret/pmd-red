// platform/pc/gba_shim.h — PC backend declarations (host builds only).
//
// The GBA headers themselves branch on PLATFORM_PC now (see include/gba/
// defines.h, io_reg.h, macro.h), so this header only declares the C functions
// the PC backends provide: BIOS syscall replacements + video/input/audio/save.
//
// Compile game sources with -DPLATFORM_PC; no -include flag needed.
#ifndef PMDRED_PC_GBA_SHIM_H
#define PMDRED_PC_GBA_SHIM_H

#ifdef PLATFORM_PC

// ---- BIOS syscall replacements (cpu_pc.c) ----
// Signatures match libagbsyscall so game call sites need no edits.
void Pc_MemInit(void);       // zero VRAM/PLTT/OAM + regs, KEYINPUT idle
void Pc_VBlankCommit(void);  // PC replacement for the VBlank_CB register reloads
void Pc_RequestVBlank(void); // set by the host 60Hz loop; consumed by VBlankIntrWait

// ---- Video backend (video_pc.c) ----
void Pc_VideoInit(int scale);      // init framebuffer/window (SDL if HAVE_SDL2)
void Pc_VideoPresent(void);        // composite shadows -> screen, 240x160 scaled
void Pc_VideoShutdown(void);
void Pc_VideoDumpPPM(const char *path); // headless framebuffer dump (no SDL needed)

// ---- Input backend (input_pc.c) ----
void Pc_InputInit(void);
void Pc_InputPump(void); // refresh REG_KEYINPUT shadow (active-low, KEYS_MASK idle)
void Pc_InputShutdown(void);

// ---- Audio backend (audio_pc.c, mute-first) ----
void Pc_AudioInit(void);
void Pc_AudioFrame(void); // called once per 60Hz tick; noop until sequencer lands
void Pc_AudioShutdown(void);

// ---- Save backend (save_pc.c) ----
void Pc_SaveInit(const char *dir); // host save dir (default ~/.pmd-red)
void Pc_SaveFlush(void);

#endif // PLATFORM_PC
#endif // PMDRED_PC_GBA_SHIM_H
