// platform/pc/rom_load_stubs.c — empty generated-table defaults for the
// backend-only smoke binary (pmd-red-pc, which links no blobs). The full-game
// binary links the real rom_slices_all.o / blob_addrs.o instead.
#include "rom_load.h"

const PcRomSlice pcRomSliceTable[1] = {{ NULL, 0, 0, 0 }};
const unsigned pcRomSliceCount = 0;

const PcGbaAddr pcGbaAddrTable[1] = {{ 0, 0, NULL }};
const unsigned pcGbaAddrCount = 0;

const unsigned int *const pcGbaRelocTable[1] = { NULL };
const unsigned pcGbaRelocCount = 0;

const unsigned int *const pcSliceRelocTable[1] = { NULL };
const unsigned pcSliceRelocCount = 0;