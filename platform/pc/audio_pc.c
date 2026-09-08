// platform/pc/audio_pc.c — mute-first audio backend.
//
// Stage 1: all init/frame calls are noops so the game boots without the m4a
// mixer (src/m4a.c + src/m4a_1.s are excluded from the host build; see
// platform/pc/Makefile.pc). Stage 2: SDL_Audio sequencer fed by
// sound/songs/midi/*.mid + direct_sound_samples (see docs/PC_PORT_INVENTORY.md).
#include "gba_shim.h"

void Pc_AudioInit(void) {}
void Pc_AudioFrame(void) {}
void Pc_AudioShutdown(void) {}
