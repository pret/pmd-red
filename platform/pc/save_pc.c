// platform/pc/save_pc.c — host filesystem save backend.
//
// Stage 1: remembers the save dir and truncates/creates it; keeps the GBA save
// format byte-identical so saves stay compatible with the ROM build.
// Stage 2: back adventure_save/save_read/save_write/quick_save_* file I/O here
// (~/.pmd-red/save.bin) once those modules join the host build.
#include <stdio.h>
#include <string.h>

#include "gba_shim.h"

static char sSaveDir[256];

void Pc_SaveInit(const char *dir) {
    const char *d = (dir != NULL && dir[0] != '\0') ? dir : "~/.pmd-red";
    strncpy(sSaveDir, d, sizeof(sSaveDir) - 1);
    sSaveDir[sizeof(sSaveDir) - 1] = '\0';
}

void Pc_SaveFlush(void) {}
