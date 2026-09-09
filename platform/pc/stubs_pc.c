// platform/pc/stubs_pc.c — host stubs for not-yet-ported HW-coupled units.
//
// These satisfy the link so real game modules run on host (boot vectors,
// link play). The m4a sound engine used to live here as noops; it is now
// implemented for real in platform/pc/m4a_port.c.
#include "global.h"

// ---- Boot / interrupt vectors (replaced by the host 60Hz loop) ----
u32 IntrMain[0x120 / sizeof(u32)]; // crt0.s never assembles on host; address-taken only
u32 gUnknown_3004000;              // IWRAM scratch (ld_script 0x3002090); address-taken only

u32 sub_80001E8(void) { return 0; } // arm_funcs.s link-play copy source; host has no link play
void sub_8000228(void) {}           // arm_funcs.s SIO ISR; host has no link play

// ---- m4a sound engine: implemented for real in platform/pc/m4a_port.c ----
// (player open/start/stop/fade/volume, MPlayMain scheduler, ply_* command
// handlers, ply_note channel setup) driven by generated song data
// (build/bin/gen/audio_data.c). Nothing stubbed here anymore.

// Song table (gSongTable) and player table (gMPlayTable + the eight
// gMPlayInfo_* players with real track storage) live in generated
// build/bin/gen/audio_data.c and platform/pc/m4a_port.c now.
