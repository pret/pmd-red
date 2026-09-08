// platform/pc/rom_load.c — runtime baserom.gba loader + first-launch prompt.
//
// The port never embeds ROM data at build time. Blobs whose data/*.s extract
// from baserom.gba (.incbin "baserom.gba", off, size) are built from the .s
// files with those directives replaced by .space (zero-filled), so the
// generated arrays have the correct layout. At startup we locate the user's
// own ROM dump and memcpy each slice into those arrays:
//   PATH = --rom ARGV || PMD_RED_ROM || saved config || first-run prompt
// The chosen path is remembered in a per-user config file so the prompt shows
// only once.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "gba/gba.h"
#include "rom_load.h"
#include "gba_shim.h"

#ifdef _WIN32
#include <windows.h>
#include <commdlg.h>
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
#ifdef _WIN32
#include <windows.h>
#else
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

static const char *Pc_HomeDir(void) {
    const char *home = getenv("USERPROFILE");
    if (home == NULL || home[0] == '\0')
        home = getenv("HOME");
    return (home && home[0]) ? home : "";
}

static void Pc_ConfigPath(char *out, size_t cap) {
    snprintf(out, cap, "%s/.pmd-red/rom_path.txt", Pc_HomeDir());
}

static void Pc_LoadSavedPath(void) {
    char cfg[1032];
    FILE *f;
    Pc_ConfigPath(cfg, sizeof(cfg));
    f = fopen(cfg, "r");
    if (f != NULL) {
        size_t n = fread(sRomPath, 1, sizeof(sRomPath) - 1, f);
        if (n > 0) {
            sRomPath[n] = '\0';
            // trim trailing newline
            while (n > 0 && (sRomPath[n - 1] == '\n' || sRomPath[n - 1] == '\r')) {
                sRomPath[--n] = '\0';
            }
        }
        fclose(f);
    }
}

static void Pc_SaveSelectedPath(void) {
    char cfg[1032], dir[1032];
    FILE *f;
    Pc_ConfigPath(cfg, sizeof(cfg));
    snprintf(dir, sizeof(dir), "%s/.pmd-red", Pc_HomeDir());
#ifdef _WIN32
    CreateDirectoryA(dir, NULL);
#else
    // best-effort mkdir via shell-free approach; parent usually exists
#endif
    f = fopen(cfg, "w");
    if (f != NULL) {
        fputs(sRomPath, f);
        fclose(f);
    }
}

// First-launch prompt. On Windows use the native open-file dialog; otherwise
// fall back to a console prompt. Writes the selection into sRomPath.
static int Pc_PromptForRom(void) {
#ifdef _WIN32
    OPENFILENAMEA ofn;
    char file[2048] = "";
    memset(&ofn, 0, sizeof(ofn));
    ofn.lStructSize = sizeof(ofn);
    ofn.lpstrFilter = "Game Boy Advance ROM (*.gba)\0*.gba\0All files (*.*)\0*.*\0";
    ofn.lpstrFile = file;
    ofn.nMaxFile = sizeof(file);
    ofn.Flags = OFN_FILEMUSTEXIST | OFN_PATHMUSTEXIST;
    ofn.lpstrTitle = "Select Pokemon Mystery Dungeon: Red Rescue Team (baserom.gba)";
    if (GetOpenFileNameA(&ofn)) {
        strncpy(sRomPath, file, sizeof(sRomPath) - 1);
        sRomPath[sizeof(sRomPath) - 1] = '\0';
        return 1;
    }
    return 0;
#else
    fprintf(stdout,
            "You are launching pmd-red for the first time.\n"
            "Please provide a dump of Pokemon Mystery Dungeon: Red Rescue Team\n"
            "(the original GBA ROM; sha1 9f4cfc5b5f4859d17169a485462e977c7aac2b89).\n"
            "ROM path: ");
    fflush(stdout);
    if (fgets(sRomPath, sizeof(sRomPath), stdin) != NULL) {
        int n = (int)strlen(sRomPath);
        while (n > 0 && (sRomPath[n - 1] == '\n' || sRomPath[n - 1] == '\r'))
            sRomPath[--n] = '\0';
        if (n > 0)
            return 1;
    }
    return 0;
#endif
}

const char *Pc_RomPath(void) {
    return sRomPath;
}

int Pc_RomLoad(const char *explicitPath) {
    FILE *f = NULL;
    unsigned char *buf = NULL;
    unsigned i, needEnd = 0;

    if (sLoaded)
        return 0;

    if (explicitPath != NULL && explicitPath[0] != '\0') {
        strncpy(sRomPath, explicitPath, sizeof(sRomPath) - 1);
        sRomPath[sizeof(sRomPath) - 1] = '\0';
    } else {
        const char *env = getenv("PMD_RED_ROM");
        if (env != NULL && env[0] != '\0') {
            strncpy(sRomPath, env, sizeof(sRomPath) - 1);
            sRomPath[sizeof(sRomPath) - 1] = '\0';
        } else {
            sRomPath[0] = '\0';
            Pc_LoadSavedPath();
            if (sRomPath[0] == '\0') {
                if (!Pc_PromptForRom())
                    return 1;
                Pc_SaveSelectedPath();
            }
        }
    }

    if (sRomPath[0] == '\0')
        return 1;

    f = fopen(sRomPath, "rb");
    if (f == NULL) {
        fprintf(stderr, "pmd-red-pc: cannot open selected ROM: %s\n", sRomPath);
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