// platform/pc/save_pc.c — host filesystem save backend.
//
// Emulates the GBA flash chip with a single host file ("rescue-team.sav")
// so the GBA save format stays byte-identical and saves remain compatible
// with the ROM build. Sector size matches the GBA flash (0x1000 bytes);
// the image is 512KB (0x80000) which covers every sector the game uses:
//   main save     sectors  0..11  (two 0x57D4-byte copies)
//   quick save    sectors 16..20  (0x4800 bytes of dungeon state)
//   save meta     sector  31      (0x800-byte unk_struct)
//
// The flash file is opened/closed per operation (saving is rare), and a
// missing or short file reads back as erased flash (0xFF) so the game's
// "no save" path is unchanged.
#include <errno.h>
#include <stdio.h>
#include <string.h>

#include "gba/gba.h"
#include "gba_shim.h"

#define PC_SAVE_FILE   "rescue-team.sav"
#define PC_FLASH_SIZE  0x80000  // 512KB, sector-aligned
#define PC_SECTOR_SIZE 0x1000

static char sSaveDir[256];

static void Pc_SavePath(char *out, size_t cap)
{
    if (sSaveDir[0] != '\0')
        snprintf(out, cap, "%s%s", sSaveDir, PC_SAVE_FILE);
    else
        snprintf(out, cap, "%s", PC_SAVE_FILE);
}

// Open the flash image, extending it to PC_FLASH_SIZE with erased (0xFF)
// bytes if it is missing or short. Returns NULL on failure.
static FILE *Pc_SaveOpen(void)
{
    char path[512];
    FILE *f;
    long size;

    Pc_SavePath(path, sizeof(path));
    f = fopen(path, "r+b");
    if (f == NULL) {
        // Missing file: create it, pre-filled with erased flash.
        f = fopen(path, "w+b");
        if (f == NULL)
            return NULL;
    }

    if (fseek(f, 0, SEEK_END) != 0) {
        fclose(f);
        return NULL;
    }
    size = ftell(f);
    if (size < 0 || size > PC_FLASH_SIZE) {
        fclose(f);
        return NULL;
    }

    if (size < PC_FLASH_SIZE) {
        // Extend with 0xFF to the full image size.
        char buf[PC_SECTOR_SIZE];
        long missing = PC_FLASH_SIZE - size;

        memset(buf, 0xFF, sizeof(buf));
        while (missing > 0) {
            size_t n = (missing > (long)sizeof(buf)) ? sizeof(buf) : (size_t)missing;
            if (fwrite(buf, 1, n, f) != n) {
                fclose(f);
                return NULL;
            }
            missing -= (long)n;
        }
        if (fflush(f) != 0) {
            fclose(f);
            return NULL;
        }
    }

    return f;
}

void Pc_SaveInit(const char *dir) {
    if (dir != NULL && dir[0] != '\0') {
        strncpy(sSaveDir, dir, sizeof(sSaveDir) - 1);
        sSaveDir[sizeof(sSaveDir) - 1] = '\0';
    } else {
        sSaveDir[0] = '\0';
    }
}

// Read `size` bytes from the flash image at `sector * 0x1000`. A missing or
// short region reads as erased flash (0xFF). Returns 0 on success, 3 on I/O
// failure (matching ReadFlashData's error return).
int Pc_SaveRead(s32 sector, u8 *dest, s32 size)
{
    FILE *f;
    long offset = (long)sector * PC_SECTOR_SIZE;

    if (sector < 0 || offset < 0 || size <= 0) {
        if (size > 0)
            memset(dest, 0xFF, size);
        return 3;
    }

    f = Pc_SaveOpen();
    if (f == NULL) {
        if (size > 0)
            memset(dest, 0xFF, size);
        return 3;
    }

    if (fseek(f, offset, SEEK_SET) != 0) {
        fclose(f);
        if (size > 0)
            memset(dest, 0xFF, size);
        return 3;
    }

    if (fread(dest, 1, size, f) != (size_t)size) {
        // Short read: treat the remainder as erased flash.
        long pos = ftell(f);
        size_t got = (pos > offset) ? (size_t)(pos - offset) : 0;
        if (got > (size_t)size)
            got = (size_t)size;
        memset(&dest[got], 0xFF, (size_t)size - got);
    }

    fclose(f);
    return 0;
}

// Write `size` bytes to the flash image at `sector * 0x1000`. Regions are
// always written in full at fixed offsets and start life erased (0xFF), so a
// plain overwrite matches cartridge flash behavior. Returns 0 on success, 3
// on failure (matching WriteFlashData's error return).
int Pc_SaveWrite(s32 sector, u8 *src, s32 size)
{
    FILE *f;
    long offset = (long)sector * PC_SECTOR_SIZE;

    if (sector < 0 || offset < 0 || size <= 0)
        return 3;

    f = Pc_SaveOpen();
    if (f == NULL)
        return 3;

    if (fseek(f, offset, SEEK_SET) != 0) {
        fclose(f);
        return 3;
    }

    if (fwrite(src, 1, size, f) != (size_t)size) {
        fclose(f);
        return 3;
    }

    if (fflush(f) != 0) {
        fclose(f);
        return 3;
    }

    fclose(f);
    return 0;
}

// Erase the whole chip: reset the flash image to all-0xFF (deleting it).
// Deleting a file that is already absent is not an error.
int Pc_SaveEraseChip(void)
{
    char path[512];

    Pc_SavePath(path, sizeof(path));
    if (remove(path) != 0 && errno != ENOENT)
        return 1;
    return 0;
}

void Pc_SaveFlush(void) {}