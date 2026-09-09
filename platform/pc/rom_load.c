// platform/pc/rom_load.c — runtime baserom.gba loader (required next to exe).
//
// The port never embeds ROM data at build time. Blobs whose data/*.s extract
// from baserom.gba (.incbin "baserom.gba", off, size) are built from the .s
// files with those directives replaced by .space (zero-filled), so the
// generated arrays have the correct layout. At startup we open baserom.gba
// from the executable's own directory and memcpy each slice into those arrays:
//   PATH = <exe dir>/baserom.gba  (mandatory; fail if absent)
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gba/gba.h"
#include "rom_load.h"
#include "gba_shim.h"

#ifdef _WIN32
#include <windows.h>
#endif

// Provided by gen_blobs.py: rom_slices_all.c (baserom slices) and blob_addrs.c
// (GBA-address registry + baked address-word list). The backend-only smoke
// binary links rom_load_stubs.c for the empty defaults instead.
extern const PcRomSlice pcRomSliceTable[];
extern const unsigned pcRomSliceCount;
extern const PcGbaAddr pcGbaAddrTable[];
extern const unsigned pcGbaAddrCount;
extern const unsigned int *const pcGbaRelocTable[];
extern const unsigned pcGbaRelocCount;

const void *Pc_GbaToHost(unsigned gba)
{
    // Registry is sorted by ascending gba; small enough for a linear scan that
    // only runs at content-load time. Returns the pointer for the symbol
    // whose [gba, gba+size) range contains `gba`.
    unsigned i;
    for (i = 0; i < pcGbaAddrCount; i++) {
        if (gba >= pcGbaAddrTable[i].gba &&
            gba < pcGbaAddrTable[i].gba + pcGbaAddrTable[i].size)
            return pcGbaAddrTable[i].host + (gba - pcGbaAddrTable[i].gba);
    }
    return NULL;
}

// ---- GBA ROM address-space mirror ----
//
// The game's data tables are full of baked 32-bit GBA addresses
// (0x08xxxxxx; e.g. SIRO archive `data` fields and reloc slots that
// gen_blobs writes back as ROM addresses). One clean way to make those
// dereferenceable on a 64-bit host is to map the whole GamePak ROM window
// [0x08000000, 0x0A000000) into user space and copy every blob array there.
// Then a baked 0x08xxxxxx value is, verbatim, a valid pointer.
#ifndef _WIN32
#include <sys/mman.h>
#include <limits.h>
#endif

static int sRomSpaceMapped = 0;
static unsigned char *sRomMapBase = (unsigned char *)0x08000000;

static unsigned char *Pc_MapRomSpace(void)
{
#ifdef _WIN32
    // Prefer the canonical window so baked addresses need no patching.
    void *p = VirtualAlloc((LPVOID)0x08000000, 0x02000000,
                           MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    if (p != NULL)
        return (unsigned char *)p;
    // Fall back to a free block anywhere; each baked word is re-homed below.
    p = VirtualAlloc(NULL, 0x02000000, MEM_RESERVE | MEM_COMMIT, PAGE_READWRITE);
    return (unsigned char *)p;
#else
    void *p = mmap((void *)0x08000000, 0x02000000,
                   PROT_READ | PROT_WRITE,
                   MAP_PRIVATE | MAP_ANONYMOUS | MAP_FIXED, -1, 0);
    if (p != MAP_FAILED)
        return (unsigned char *)p;
    p = mmap(NULL, 0x02000000, PROT_READ | PROT_WRITE,
             MAP_PRIVATE | MAP_ANONYMOUS, -1, 0);
    return (p == MAP_FAILED) ? NULL : (unsigned char *)p;
#endif
}

// Copy every registry array into the GBA ROM window so baked 0x08 addresses
// resolve. Must run after Pc_RomLoad (baserom slices land in the arrays
// first). Safe to call more than once.
void Pc_SetupRomAddressSpace(void)
{
    unsigned char *base;
    unsigned i;
    if (sRomSpaceMapped)
        return;
    base = Pc_MapRomSpace();
    if (base == NULL) {
        fprintf(stderr, "pmd-red-pc: WARNING could not allocate GBA ROM window; "
                        "baked 0x08xxxxxx data pointers will be invalid\n");
        return;
    }
    if (base != (unsigned char *)0x08000000) {
        // Fixed window unavailable (e.g. an ASLR-placed DLL there): re-home
        // every baked 0x08xxxxxx word to `base + delta` first, then mirror.
        for (i = 0; i < pcGbaRelocCount; i++) {
            unsigned int *w = pcGbaRelocTable[i];
            unsigned int gba = *w;
            if ((gba & 0xF8000000u) == 0x08000000u)
                *w = (unsigned)((unsigned char *)base + (gba - 0x08000000u));
        }
        fprintf(stdout, "pmd-red-pc: GBA ROM window re-homed to %p\n", (void *)base);
    }
    sRomSpaceMapped = 1;
    sRomMapBase = base;
    for (i = 0; i < pcGbaAddrCount; i++)
        memcpy(base + (pcGbaAddrTable[i].gba - 0x08000000u),
               pcGbaAddrTable[i].host, pcGbaAddrTable[i].size);
    fprintf(stdout, "pmd-red-pc: mirrored %u blob arrays into the GBA ROM window\n",
            pcGbaAddrCount);
}

static char sRomPath[1024 + 1] = "";
static int sLoaded = 0;

const char *Pc_RomPath(void) {
    return sRomPath;
}

// baserom.gba MUST sit next to the executable; no other location is searched.
// Returns 0 on success (slices filled), nonzero if the ROM is absent/invalid.
int Pc_RomLoad(const char *exeDir) {
    FILE *f = NULL;
    unsigned char *buf = NULL;
    unsigned i, needEnd = 0;

    if (sLoaded)
        return 0;

    if (exeDir != NULL && exeDir[0] != '\0')
        snprintf(sRomPath, sizeof(sRomPath), "%sbaserom.gba", exeDir);
    else
        snprintf(sRomPath, sizeof(sRomPath), "baserom.gba");

    f = fopen(sRomPath, "rb");
    if (f == NULL) {
        fprintf(stderr, "pmd-red-pc: required file not found: %s\n", sRomPath);
        return 1;
    }

    for (i = 0; i < pcRomSliceCount; i++) {
        unsigned end = pcRomSliceTable[i].srcOff + pcRomSliceTable[i].len;
        if (end > needEnd)
            needEnd = end;
    }

    // Verify length covers everything we need, then read the whole file.
    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        return 1;
    }
    {
        long sz = ftell(f);
        if (sz < (long)needEnd) {
            fprintf(stderr, "pmd-red-pc: %s too small (%ld < 0x%x) — is it the Red Rescue Team ROM?\n",
                    sRomPath, sz, needEnd);
            fclose(f);
            return 1;
        }
    }
    fseek(f, 0, SEEK_SET);

    buf = (unsigned char *)malloc(needEnd);
    if (buf == NULL) {
        fclose(f);
        return 1;
    }
    if (fread(buf, 1, needEnd, f) != needEnd) {
        fclose(f);
        free(buf);
        return 1;
    }
    fclose(f);

    for (i = 0; i < pcRomSliceCount; i++) {
        const PcRomSlice *s = &pcRomSliceTable[i];
        memcpy(s->dst + s->dstOff, buf + s->srcOff, s->len);
    }

    free(buf);
    sLoaded = 1;
    fprintf(stdout, "pmd-red-pc: loaded baserom from %s (%u slices)\n", sRomPath, pcRomSliceCount);
    return 0;
}