// platform/pc/rom_load.h — runtime baserom.gba loader (required next to exe).
#ifndef PMDRED_PC_ROM_LOAD_H
#define PMDRED_PC_ROM_LOAD_H

#include <stddef.h>

// One baserom region copied into a generated blob array at startup. Produced
// by gen_blobs.py (rom_slices_all.c) for the blobs whose data/*.s use
// .incbin "baserom.gba", ROM_OFFSET, SIZE.
typedef struct PcRomSlice {
    unsigned char *dst; // base of the writable blob array
    unsigned dstOff;    // offset into dst where the slice is copied
    unsigned srcOff;    // offset in baserom.gba
    unsigned len;
} PcRomSlice;

// GBA ROM address -> host pointer, for the baked-in 0x08xxxxxx addresses the
// game's data tables store (e.g. SIRO archive `data` fields). Produced by
// gen_blobs.py (blob_addrs.c).
typedef struct PcGbaAddr {
    unsigned gba;      // GBA start address (0x08000000..0x09FFFFFF)
    unsigned size;     // byte size of the blob array
    const unsigned char *host; // pointer to the emitted blob array
} PcGbaAddr;

// Baked 0x08xxxxxx address words inside emitted byte arrays (gen_blobs.py).
// Used to re-home them when the fixed 0x08000000 window cannot be mapped.
extern const unsigned int *const pcGbaRelocTable[];
extern const unsigned pcGbaRelocCount;

// Translate a baked GBA address to the host pointer of the owning blob array.
// Returns NULL if the address is unknown or not ROM-backed (e.g. 0x0300xxxx
// IWRAM pointers, which the PC build should never see as data addresses).
const void *Pc_GbaToHost(unsigned gba);

// Mirror every blob array into a mapped GBA ROM window at 0x08000000.. so the
// game's baked 0x08xxxxxx addresses dereference. Call after Pc_RomLoad.
void Pc_SetupRomAddressSpace(void);

// Load baserom.gba from the executable's directory and fill all slices.
// baserom.gba MUST exist next to the executable; no other path is searched.
// Returns 0 on success, nonzero if the ROM is absent or invalid.
int Pc_RomLoad(const char *exeDir);

// Path actually used ("" if none loaded yet).
const char *Pc_RomPath(void);

#endif // PMDRED_PC_ROM_LOAD_H