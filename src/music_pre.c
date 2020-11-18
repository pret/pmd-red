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

extern struct unkStruct_3000FD8 gUnknown_3000FD8[];

void sub_800BF80(void);

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

#ifndef NONMATCHING
NAKED
#endif
void FadeInNewBGM(u16 SongIndex, u16 speed)
{
#ifdef NONMATCHING
    // TODO regswap memes
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

    if((speed > 0x80 << 1))
    {
        speed = 0x10;

    }
    else
    {
        if(speed >> 4 == 0)
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
#else
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tlsls r0, 16\n"
	"\tlsrs r6, r0, 16\n"
	"\tlsls r4, r1, 16\n"
	"\tlsrs r5, r4, 16\n"
	"\tadds r0, r6, 0\n"
	"\tbl IsBGSong\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800BF2E\n"
	"\tldr r0, _0800BECC\n"
	"\tcmp r6, r0\n"
	"\tbeq _0800BF2E\n"
	"\tldr r0, _0800BED0\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r6, r0\n"
	"\tbne _0800BEBE\n"
	"\tldr r0, _0800BED4\n"
	"\tldrh r0, [r0]\n"
	"\tsubs r0, 0x1\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x1\n"
	"\tbls _0800BF2E\n"
"_0800BEBE:\n"
	"\tmovs r0, 0x80\n"
	"\tlsls r0, 1\n"
	"\tcmp r5, r0\n"
	"\tbls _0800BED8\n"
	"\tmovs r5, 0x10\n"
	"\tb _0800BEE0\n"
	"\t.align 2, 0\n"
"_0800BECC: .4byte 0x000003e7\n"
"_0800BED0: .4byte gUnknown_202D68A\n"
"_0800BED4: .4byte gUnknown_202D688\n"
"_0800BED8:\n"
	"\tlsrs r5, r4, 20\n"
	"\tcmp r5, 0\n"
	"\tbne _0800BEE0\n"
	"\tmovs r5, 0x1\n"
"_0800BEE0:\n"
	"\tbl DisableInterrupts\n"
	"\tlsls r0, 24\n"
	"\tlsrs r7, r0, 24\n"
	"\tldr r0, _0800BF34\n"
	"\tstrh r6, [r0]\n"
	"\tldr r1, _0800BF38\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, _0800BF3C\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbne _0800BF26\n"
	"\tldr r0, _0800BF40\n"
	"\tmovs r1, 0x1\n"
	"\tstrh r1, [r0]\n"
	"\tadds r0, r6, 0\n"
	"\tbl m4aSongNumStart\n"
	"\tldr r4, _0800BF44\n"
	"\tadds r0, r4, 0\n"
	"\tbl m4aMPlayImmInit\n"
	"\tadds r0, r4, 0\n"
	"\tmovs r1, 0xFF\n"
	"\tmovs r2, 0\n"
	"\tbl m4aMPlayVolumeControl\n"
	"\tadds r0, r6, 0\n"
	"\tbl m4aSongNumStop\n"
	"\tadds r0, r4, 0\n"
	"\tadds r1, r5, 0\n"
	"\tbl m4aMPlayFadeIn\n"
"_0800BF26:\n"
	"\tcmp r7, 0\n"
	"\tbeq _0800BF2E\n"
	"\tbl EnableInterrupts\n"
"_0800BF2E:\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800BF34: .4byte gUnknown_202D68A\n"
"_0800BF38: .4byte gUnknown_202D694\n"
"_0800BF3C: .4byte gUnknown_202D690\n"
"_0800BF40: .4byte gUnknown_202D688\n"
"_0800BF44: .4byte gUnknown_20008F0");
#endif
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
