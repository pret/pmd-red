#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"
#include "bg.h"
#include "music.h"

extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
extern void SoundBiasReset();
extern void SoundBiasSet();
extern void SetInterruptFlag(u16);
extern void nullsub_25();
extern void nullsub_18();

extern void sub_800C298(u16 r0);

typedef void (*IntrCallback)(void);
extern IntrCallback gUnknown_202D5F0[];

extern u32 gUnknown_203B0A0;
extern u16 gBGMusicPlayerState;
extern u16 gCurrentBGSong;
extern u16 gUnknown_202D68C;
extern u16 gUnknown_202D68E;
extern u16 gUnknown_202D690;
extern u16 gUnknown_202D692;
extern u8 gUnknown_202D694;
extern u8 gUnknown_203B099;
extern u8 gUnknown_203B09B;
extern u32 gUnknown_203B09C;
extern u8 gUnknown_203B09A;

struct unkStruct_3000FD8
{
    u16 unk0;
    u16 unk2;
    u16 unk4;
    u8 unk6;
    u8 padding;
};

extern struct unkStruct_3000FD8 gUnknown_3000FD8[8];

extern u8 gUnknown_202D7FE;
extern u16 gUnknown_202D7FC;
extern struct BGControlStruct gUnknown_202D698;
extern struct BGControlStruct gUnknown_202D6A0;
extern struct BGControlStruct gUnknown_202D6A8;
extern struct BGControlStruct gUnknown_202D6B0;

void sub_800BF80(void);
void xxx_update_bg_sound_input(void);

void sub_800BA5C(void)
{
    if(gUnknown_203B09A != 0)
    {
        gUnknown_203B09C++;
        xxx_update_bg_sound_input();
    }
    gUnknown_203B09A = 1;
    gUnknown_203B09B = 0;
    gUnknown_203B09C = 0;
    nullsub_25();

    while(REG_VCOUNT > 159){}

    gUnknown_203B099 = 1;
    VBlankIntrWait();
    nullsub_18();
}

#ifdef NONMATCHING
void xxx_update_bg_sound_input(void)
{
    u8 store;
    store = gUnknown_203B09B;
    if(gUnknown_203B09B != 0){
        gUnknown_203B09C++;
    }
    else {
        gUnknown_203B09B = 1;
        gUnknown_203B09A = store;
        gUnknown_203B09C = store;
        UpdateBGControlRegisters();
        if(gUnknown_203B099 != 0)
            UpdateSound();
        UpdateInput();
        gUnknown_203B099 = store;
        gUnknown_203B0A4 = gUnknown_203B0A0;
    }
}
#else
NAKED
void xxx_update_bg_sound_input(void)
{
	asm_unified("\tpush {r4,r5,lr}\n"
	"\tldr r1, _0800BACC\n"
	"\tldrb r4, [r1]\n"
	"\tcmp r4, 0\n"
	"\tbeq _0800BAD4\n"
	"\tldr r1, _0800BAD0\n"
	"\tldr r0, [r1]\n"
	"\tadds r0, 0x1\n"
	"\tstr r0, [r1]\n"
	"\tb _0800BAFE\n"
	"\t.align 2, 0\n"
"_0800BACC: .4byte gUnknown_203B09B\n"
"_0800BAD0: .4byte gUnknown_203B09C\n"
"_0800BAD4:\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1]\n"
	"\tldr r0, _0800BB04\n"
	"\tstrb r4, [r0]\n"
	"\tldr r0, _0800BB08\n"
	"\tstr r4, [r0]\n"
	"\tbl UpdateBGControlRegisters\n"
	"\tldr r5, _0800BB0C\n"
        "\tldrb r0, [r5]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800BAF0\n"
	"\tbl UpdateSound\n"
"_0800BAF0:\n"
	"\tbl UpdateInput\n"
	"\tstrb r4, [r5]\n"
	"\tldr r0, _0800BB10\n"
	"\tldr r1, _0800BB14\n"
	"\tldr r1, [r1]\n"
	"\tstr r1, [r0]\n"
"_0800BAFE:\n"
	"\tpop {r4,r5}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800BB04: .4byte gUnknown_203B09A\n"
"_0800BB08: .4byte gUnknown_203B09C\n"
"_0800BB0C: .4byte gUnknown_203B099\n"
"_0800BB10: .4byte gUnknown_203B0A4\n"
"_0800BB14: .4byte gUnknown_203B0A0");
}
#endif

void Timer3Intr(void)
{
    if(gUnknown_202D5F0[4])
        gUnknown_202D5F0[4]();
    SetInterruptFlag(INTR_FLAG_TIMER3);
}

// Unused
u32 sub_800BB34(void)
{
    return gUnknown_203B0A0;
}

void nullsub_178(void)
{
}

// Unused
void sub_800BB44(void)
{
    u16 ie_store;
    u16 dispcnt_store;
    bool8 interrupt_flag;

    while(REG_KEYINPUT != 0x3ff){}

    interrupt_flag = DisableInterrupts();

    while(REG_VCOUNT <= 159){}

    dispcnt_store = REG_DISPCNT;
    REG_DISPCNT = 0x80;

    *(vu16 *)BG_PLTT = 0x7fff;

    ie_store = REG_IE;
    REG_IE = INTR_FLAG_KEYPAD | INTR_FLAG_GAMEPAK;

    REG_KEYCNT = 0x8304;
    REG_IME = 1;

    SoundBiasReset();
    asm("swi 0x3");
    SoundBiasSet();

    REG_IME = 0;
    REG_IE = ie_store;
    REG_KEYCNT = 0;
    REG_DISPCNT = dispcnt_store;
    *(vu16 *)BG_PLTT = 0;

    if(interrupt_flag)
        EnableInterrupts();
    while(REG_KEYINPUT != 0x3ff){}
}

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

    gBGMusicPlayerState = 0;
    gCurrentBGSong = 999;
    gUnknown_202D68C = 999;
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


void StartNewBGM(u16 songIndex)
{
    bool8 interrupt_flag;
    u16 temp_store;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == 999)
        return;
    if(songIndex == gCurrentBGSong)
    {
        temp_store = gBGMusicPlayerState - 1;
        if(temp_store <= 1)
            return;
    }
    if(sub_800CAE0(songIndex))
    {
        nullsub_20(songIndex);
        return;
    }
    interrupt_flag = DisableInterrupts();
    gCurrentBGSong = songIndex;
    gUnknown_202D694 = 1;

    if(gUnknown_202D690 == 0)
    {
        gBGMusicPlayerState = 1;
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
    if(SongIndex == 999)
        return;
    if(SongIndex == gCurrentBGSong)
    {
        temp_store = gBGMusicPlayerState - 1;
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
    gCurrentBGSong = SongIndex;
    gUnknown_202D694 = 1;

    if(gUnknown_202D690 == 0)
    {
        gBGMusicPlayerState = 1;
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
    u16 preload  = gCurrentBGSong;
    if(preload == 999)
    {
        StartNewBGM(SongIndex);
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
        if(gCurrentBGSong != 999)
        {
            m4aMPlayStop(&gUnknown_20008F0);
        }
    }
    gCurrentBGSong = 999;
    gUnknown_202D68C = 999;
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
        if(gCurrentBGSong != 999)
        {
            if(gBGMusicPlayerState == 2)
            {
                gBGMusicPlayerState = 3;
                m4aMPlayFadeOut(&gUnknown_20008F0, speed);
            }
            else
            {
                gCurrentBGSong = 999;
                m4aMPlayStop(&gUnknown_20008F0);
            }
        }
    }
    else
    {
        gCurrentBGSong = 999;
    }
    gUnknown_202D68C = 999;
    if(interrupt_flag)
        EnableInterrupts();
}

u16 GetCurrentBGSong(void)
{
    return gCurrentBGSong;
}
