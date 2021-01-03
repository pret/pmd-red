#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"

extern void nullsub_19(void);
extern void nullsub_20(u16 songIndex);
extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
extern bool8 IsBGSong(u32);

extern void sub_800C298(u16 r0);
extern u16 sub_800CAE0(u16);

extern u32 gUnknown_202D5F0[];
extern u16 gUnknown_202D688;
extern u16 gUnknown_202D68A;
extern u16 gUnknown_202D68C;
extern u16 gUnknown_202D68E;
extern u16 gUnknown_202D690;
extern u16 gUnknown_202D692;
extern u8 gUnknown_202D694;

struct unkStruct_3000FD8
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 padding;
};

extern struct unkStruct_3000FD8 gUnknown_3000FD8[8];

struct BGControlStruct
{
    u16 padding;
    u16 unk2;
    s16 hofs;
    s16 vofs;
};

extern u8 gUnknown_202D7FE;
extern u16 gUnknown_202D7FC;
extern struct BGControlStruct gUnknown_202D698;
extern struct BGControlStruct gUnknown_202D6A0;
extern struct BGControlStruct gUnknown_202D6A8;
extern struct BGControlStruct gUnknown_202D6B0;

void sub_800BF80(void);

void nullsub_17(void)
{
}

void UpdateBGControlRegisters(void)
{
    u32 BG[4];

    if(gUnknown_202D7FE == 1)
    {
        BG[0] = 1;
        BG[1] = 2;
        BG[2] = 0;
        BG[3] = 3;
    }
    else
    {
        BG[0] = 0;
        BG[1] = 1;
        BG[2] = 2;
        BG[3] = 3;
    }

    REG_BG0HOFS = gUnknown_202D698.hofs;
    REG_BG0VOFS = gUnknown_202D698.vofs;
    REG_BG1HOFS = gUnknown_202D6A0.hofs;
    REG_BG1VOFS = gUnknown_202D6A0.vofs;
    REG_BG2HOFS = gUnknown_202D6A8.hofs;
    REG_BG2VOFS = gUnknown_202D6A8.vofs;
    REG_BG3HOFS = gUnknown_202D6B0.hofs;
    REG_BG3VOFS = gUnknown_202D6B0.vofs;

    REG_BG0CNT = BG[0] | 0xB0 << 6;
    REG_BG1CNT = BG[1] | 0xB4 << 6;
    if(gUnknown_202D6A8.unk2 == 0x80 << 8)
    {
        REG_BG2CNT = BG[2] | 0x2e08;
    }
    else
    {
        REG_BG2CNT = BG[2] | 0xB8 << 6;
    }

    REG_BG3CNT = BG[3] | 0x2f08;
    REG_BLDCNT = gUnknown_202D7FC;
}

// Some kind of initializer for music?
void sub_800BD08(void)
{
    s32 counter;
    u16 zero;
    u16 zero2;

    struct unkStruct_3000FD8 *preload;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    m4aSoundInit();

    gUnknown_202D688 = 0;
    gUnknown_202D68A = 0x3e7;
    gUnknown_202D68C = 0x3e7;
    gUnknown_202D68E = 0x3e5;
    gUnknown_202D690 = 0;
    gUnknown_202D692 = 0;
    gUnknown_202D694 = 0;

    // Kinda hacky but makes things match
    preload = gUnknown_3000FD8;
    zero = 0;
    zero2 = 0;
    counter = 7;

    while(counter >= 0)
    {
        preload->unk0 = zero2;
        preload->unk2 = 0x3e5;
        preload->unk4 = zero2;
        preload->unk6 = zero;
        counter--;
        preload++;
    }
    nullsub_19();
}

void sub_800BDDC(void)
{
    sub_800BF80();
    sub_800C298(0x3e6);
    sub_800C298(0x3e5);
}


void sub_800BDFC(u16 songIndex)
{
    bool8 interrupt_flag;
    u16 temp_store;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == 0x3e7)
        return;
    if(songIndex == gUnknown_202D68A)
    {
        temp_store = gUnknown_202D688 - 1;
        if(temp_store <= 1)
            return;
    }
    if(sub_800CAE0(songIndex))
    {
        nullsub_20(songIndex);
        return;
    }
    interrupt_flag = DisableInterrupts();
    gUnknown_202D68A = songIndex;
    gUnknown_202D694 = 1;

    if(gUnknown_202D690 == 0)
    {
        gUnknown_202D688 = 1;
        m4aSongNumStart(songIndex);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeInNewBGM(u16 SongIndex, u16 speed)
{
    bool8 interrupt_flag;
    u16 temp_store;

    if(!IsBGSong(SongIndex))
        return;
    if(SongIndex == 0x3e7)
        return;
    if(SongIndex == gUnknown_202D68A)
    {
        temp_store = gUnknown_202D688 - 1;
        if((temp_store) <= 1)
            return;
    }

    if((speed > 256))
    {
        speed = 16;

    }
    else
    {
        if((speed >>= 4) == 0)
        {
            speed = 1;
        }
    }

    interrupt_flag = DisableInterrupts();
    gUnknown_202D68A = SongIndex;
    gUnknown_202D694 = 1;

    if(gUnknown_202D690 == 0)
    {
        gUnknown_202D688 = 1;
        m4aSongNumStart(SongIndex);
        m4aMPlayImmInit(&gUnknown_20008F0);
        m4aMPlayVolumeControl(&gUnknown_20008F0, 0xFF, 0);
        m4aSongNumStop(SongIndex);
        m4aMPlayFadeIn(&gUnknown_20008F0, speed);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void sub_800BF48(u16 SongIndex)
{
    u16 preload  = gUnknown_202D68A;
    if(preload == 0x3e7)
    {
        sub_800BDFC(SongIndex);
        gUnknown_202D68C = preload;
        return;
    }
    gUnknown_202D68C = SongIndex;
}

void sub_800BF80(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    if(gUnknown_202D690 == 0)
    {
        if(gUnknown_202D68A != 0x3e7)
        {
            m4aMPlayStop(&gUnknown_20008F0);
        }
    }
    gUnknown_202D68A = 0x3e7;
    gUnknown_202D68C = 0x3e7;
    if(interrupt_flag)
        EnableInterrupts();
}

void sub_800BFD0(u16 speed)
{

    u32 comparison;
    bool8 interrupt_flag;

    // TODO clean this comparison up
    comparison = 0x80 << 17; // 16777216
    if((speed * 65536) > comparison)
    {
        speed = 16;
    }
    else
    {
        if((speed >>= 4) == 0)
        {
            speed = 1;
        }
    }
    interrupt_flag = DisableInterrupts();
    if(gUnknown_202D690 == 0)
    {
        if(gUnknown_202D68A != 0x3e7)
        {
            if(gUnknown_202D688 == 2)
            {
                gUnknown_202D688 = 3;
                m4aMPlayFadeOut(&gUnknown_20008F0, speed);
            }
            else
            {
                gUnknown_202D68A = 0x3e7;
                m4aMPlayStop(&gUnknown_20008F0);
            }
        }
    }
    else
    {
        gUnknown_202D68A = 0x3e7;
    }
    gUnknown_202D68C = 0x3e7;
    if(interrupt_flag)
        EnableInterrupts();
}

u16 sub_800C068(void)
{
    return gUnknown_202D68A;
}
