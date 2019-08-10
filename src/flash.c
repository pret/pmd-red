#include "global.h"
#include "gba/flash.h"
#include "flash.h"
#include "memory.h"

extern u8 gFlashEnabled;

extern FlashIntrFunc *sub_800B6E8(s32);

static u8 TryProgramSector(s32, u8 *);

void InitFlash(void)
{
    if (!IdentifyFlash() && !SetFlashTimerIntr(2, sub_800B6E8(3)))
        gFlashEnabled = TRUE;
}

void ClearFlashData(void)
{
    if (gFlashEnabled)
        EraseFlashChip();
}

s32 ReadFlashData(s32 sector, u8 *dest, s32 size)
{
    if (gFlashEnabled)
    {
        u8 *_dest = dest;

        while (size >= 0x1000)
        {
            ReadFlash(sector, 0, _dest, 0x1000);
            sector++;
            _dest += 0x1000;
            size -= 0x1000;
        }

        if (size > 0)
            ReadFlash(sector, 0, _dest, size);
        return 0;
    }

    return 3;
}

s32 WriteFlashData(s32 sector, u8 *src, s32 size)
{
    u8 buffer[0x1000];

    if (gFlashEnabled)
    {
        u8 flag = TRUE;
        u8 *_src = src;

        while (size >= 0x1000)
        {
            flag = TryProgramSector(sector, _src);
            if (!flag)
                break;
            sector++;
            _src += 0x1000;
            size -= 0x1000;
        }

        if (flag)
        {
            if (size > 0)
            {
                MemoryFill8(buffer, 0xFF, 0x1000);
                MemoryCopy8(buffer, _src, size);
                flag = TryProgramSector(sector, buffer);
            }
            if (flag)
                return 0;
        }
    }

    return 3;
}

static u8 TryProgramSector(s32 sector, u8 *src)
{
    s32 tries = 3;

    do
    {
        if (!ProgramFlashSector(sector, src) && !VerifyFlashSectorNBytes(sector, src, 0x1000))
            return TRUE;
    } while (tries-- > 0);

    return FALSE;
}
