#include "global.h"
#include "random.h"
#include "flash.h"
#include "text.h"

extern char ewram_start[];

extern u16 gUnknown_202D7FC;
extern u8 gUnknown_202D7FE;

extern char alt_203B038[];

extern char gTitlePaletteFile[];
extern char gUnknown_203BC04[];

extern char iwram_start[];

extern char alt_3001B58[];

extern char unk_code_ram[];
extern char unk_code_ram_end[];

extern u8 gUnknown_80B9BF1[];

extern char gUnknown_8270000[];

extern char unk_code[];

extern void sub_800CDA8(int);
extern void sub_800B540(void);
extern void InitSprites(void);
extern void nullsub_9(void);
extern void nullsub_6(void);
extern void InitInput(void);
extern void InitBGPaletteBuffer(void);
extern void sub_80057E8(void);
extern void InitFileSystem(void);
extern void sub_80098A0(void);
extern void InitGraphics(void);
extern void sub_800B6F4(int, void *);
extern void GameLoop(void);
extern void Hang(void);
extern void sub_800CE54(void);

void AgbMain(void)
{
    u8 value[4];
    u8 seed[6];

    REG_WAITCNT = WAITCNT_PREFETCH_ENABLE | WAITCNT_WS0_S_1 | WAITCNT_WS0_N_3;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    if (gUnknown_203BC04 - gTitlePaletteFile > 0)
        CpuCopy32(gUnknown_8270000, gTitlePaletteFile, gUnknown_203BC04 - gTitlePaletteFile);

    if (alt_203B038 - ewram_start > 0)
    {
        memset(value, 0, 4);
        CpuSet(&value, ewram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_203B038 - ewram_start) / 4) & 0x1FFFFF));
    }

    if (unk_code_ram_end - unk_code_ram > 0)
        CpuCopy32(unk_code, unk_code_ram, unk_code_ram_end - unk_code_ram);

    if (alt_3001B58 - iwram_start > 0)
    {
        memset(value, 0, 4);
        CpuSet(&value, iwram_start, CPU_SET_SRC_FIXED | CPU_SET_32BIT | (((alt_3001B58 - iwram_start) / 4) & 0x1FFFFF));
    }

    REG_WIN0H = 0;
    REG_WIN1H = 0;
    REG_WIN0V = 0;
    REG_WIN1V = 0;
    REG_WININ = 16191;
    REG_WINOUT = 61;
    gUnknown_202D7FC = REG_BLDCNT = 15426;
    REG_BLDALPHA = 1546;
    gUnknown_202D7FE = 0;
    REG_BG0CNT = 11264;
    REG_BG1CNT = 11521;
    REG_BG2CNT = 11786;
    REG_BG3CNT = 12043;
    REG_DISPCNT = 32704;
    sub_800CDA8(1);
    sub_800B540();
    InitFlash();
    memcpy(seed, gUnknown_80B9BF1, 6);
    SeedRng(seed);
    InitSprites();
    nullsub_9();
    nullsub_6();
    InitInput();
    InitBGPaletteBuffer();
    sub_80057E8();
    InitFileSystem();
    LoadCharmaps();
    sub_80098A0();
    InitGraphics();
    sub_800B6F4(1, sub_800CE54);
    REG_DISPCNT = 32576;
    GameLoop();
    Hang();
}
