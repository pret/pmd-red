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
extern void UpdateSound();
extern void UpdateInput();

extern void sub_800C298(u16 r0);

typedef void (*IntrCallback)(void);
extern IntrCallback gUnknown_202D5F0[];

extern struct MusicPlayerInfo gUnknown_20008F0; // BGM??
extern u32 gUnknown_203B0A0;
extern u32 gUnknown_203B0A4;
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
    u16 songIndex;
    u16 unk4;
    u8 unk6;
};

extern struct unkStruct_3000FD8 gUnknown_3000FD8[8];

extern u8 gUnknown_202D7FE;
extern u16 gUnknown_202D7FC;
extern struct BGControlStruct gBG0Control;
extern struct BGControlStruct gBG1Control;
extern struct BGControlStruct gBG2Control;
extern struct BGControlStruct gBG3Control;

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

    REG_BG0HOFS = gBG0Control.hofs;
    REG_BG0VOFS = gBG0Control.vofs;
    REG_BG1HOFS = gBG1Control.hofs;
    REG_BG1VOFS = gBG1Control.vofs;
    REG_BG2HOFS = gBG2Control.hofs;
    REG_BG2VOFS = gBG2Control.vofs;
    REG_BG3HOFS = gBG3Control.hofs;
    REG_BG3VOFS = gBG3Control.vofs;

    REG_BG0CNT = BG[0] | 0xB0 << 6;
    REG_BG1CNT = BG[1] | 0xB4 << 6;
    if(gBG2Control.unk2 == 0x80 << 8)
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
        preload->songIndex = 0x3e5;
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

#ifdef NONMATCHING
void sub_800C074(u16 SongIndex,u16 param_2)
{
  bool8 interrupt_flag;
  u16 msVar;
  struct unkStruct_3000FD8 *preload;

  if (SongIndex == 0x3e5)
    return;
  if (0x100 < param_2)
    param_2 = 0x100;

  if (sub_800CACC(SongIndex)) 
  {
    msVar = sub_800CAE0(SongIndex);
    if (msVar == 1) {
      interrupt_flag = DisableInterrupts();
      gUnknown_202D68E = SongIndex;
      if(gUnknown_202D690 == 0)
      {
        if (gCurrentBGSong != 999) 
        {
            if ((u16)(gBGMusicPlayerState - 1U) < 2) 
            {
                gUnknown_202D690 = msVar;
                gUnknown_202D692 = 16;
                gUnknown_202D694 = 0;
                m4aMPlayFadeOutTemporarily(&gUnknown_20008F0,1);
            }
            else 
            {
                if (gBGMusicPlayerState == 3)
                    gUnknown_202D690 = 2;
                else
                {
                    gUnknown_202D690 = 3;
                    m4aMPlayStop(&gUnknown_20008F0);
                    m4aSongNumStart(gUnknown_202D68E);
                }
            }
        }
      }
      else
      {
        if (1 < (u16)(gUnknown_202D690 - 1U)) 
        {
            m4aMPlayStop(&gUnknown_20008F0);
            m4aSongNumStart(gUnknown_202D68E);
            gUnknown_202D690 = 3;
        }
      }
      switch(gCurrentBGSong)
      {
        case 26: // 0x1A
        case 27: // 0x1B
        case 28: // 0x1C
        case 29: // 0x1D
        case 30: // 0x1E
        case 31: // 0x1F
        case 34: // 0x22
        case 35: // 0x23
        case 37: // 0x25
        case 38: // 0x26
        case 117: // 0x75
        case 118: // 0x76
        case 119: // 0x77
        case 122: // 0x7A
        case 127: // 0x7F
            gUnknown_202D694 = 1;
            break;
        default:
            break;
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
    else
    {
        nullsub_20(SongIndex);
    }
  }
  else
  {
    if (!sub_800CAAC(SongIndex))
      return;
    msVar = sub_800CAE0(SongIndex);
    preload = &gUnknown_3000FD8[msVar]; // need to load this before comparison to match
    if (msVar <= 1)
        nullsub_20(SongIndex);
    else
    {
      interrupt_flag = DisableInterrupts();
      m4aSongNumStart(SongIndex);
      preload->unk0 = 1;
      preload->songIndex = SongIndex;
      // TODO fix this comparison
      // Generates eor/neg/lsr
      preload->unk6 = param_2 != 0x100;
      preload->unk4 = param_2;
      if (interrupt_flag)
        EnableInterrupts();
    }
  }
}
#else
NAKED
void sub_800C074(u16 SongIndex, u16 param_2)
{
	asm_unified("\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tlsls r0, 16\n"
	"\tlsrs r5, r0, 16\n"
	"\tmov r8, r5\n"
	"\tlsls r1, 16\n"
	"\tlsrs r6, r1, 16\n"
	"\tldr r0, _0800C0FC\n"
	"\tcmp r5, r0\n"
	"\tbne _0800C08C\n"
	"\tb _0800C208\n"
"_0800C08C:\n"
	"\tmovs r7, 0x80\n"
	"\tlsls r7, 1\n"
	"\tcmp r6, r7\n"
	"\tbls _0800C096\n"
	"\tadds r6, r7, 0\n"
"_0800C096:\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_800CACC\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbne _0800C0A4\n"
	"\tb _0800C1B0\n"
"_0800C0A4:\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_800CAE0\n"
	"\tlsls r0, 16\n"
	"\tlsrs r7, r0, 16\n"
	"\tcmp r7, 0x1\n"
	"\tbeq _0800C0B4\n"
	"\tb _0800C1D0\n"
"_0800C0B4:\n"
	"\tbl DisableInterrupts\n"
	"\tlsls r0, 24\n"
	"\tlsrs r0, 24\n"
	"\tmov r8, r0\n"
	"\tldr r6, _0800C100\n"
	"\tstrh r5, [r6]\n"
	"\tldr r4, _0800C104\n"
	"\tldrh r0, [r4]\n"
	"\tadds r2, r0, 0\n"
	"\tcmp r2, 0\n"
	"\tbne _0800C144\n"
	"\tldr r0, _0800C108\n"
	"\tldrh r1, [r0]\n"
	"\tldr r0, _0800C10C\n"
	"\tcmp r1, r0\n"
	"\tbeq _0800C12C\n"
	"\tldr r0, _0800C110\n"
	"\tldrh r1, [r0]\n"
	"\tsubs r0, r1, 0x1\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x1\n"
	"\tbhi _0800C120\n"
	"\tstrh r7, [r4]\n"
	"\tldr r1, _0800C114\n"
	"\tmovs r0, 0x10\n"
	"\tstrh r0, [r1]\n"
	"\tldr r0, _0800C118\n"
	"\tstrb r2, [r0]\n"
	"\tldr r0, _0800C11C\n"
	"\tmovs r1, 0x1\n"
	"\tbl m4aMPlayFadeOutTemporarily\n"
	"\tb _0800C15E\n"
	"\t.align 2, 0\n"
"_0800C0FC: .4byte 0x000003e5\n"
"_0800C100: .4byte gUnknown_202D68E\n"
"_0800C104: .4byte gUnknown_202D690\n"
"_0800C108: .4byte gCurrentBGSong\n"
"_0800C10C: .4byte 0x000003e7\n"
"_0800C110: .4byte gBGMusicPlayerState\n"
"_0800C114: .4byte gUnknown_202D692\n"
"_0800C118: .4byte gUnknown_202D694\n"
"_0800C11C: .4byte gUnknown_20008F0\n"
"_0800C120:\n"
	"\tlsls r0, r1, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x3\n"
	"\tbne _0800C12C\n"
	"\tmovs r0, 0x2\n"
	"\tb _0800C15C\n"
"_0800C12C:\n"
	"\tmovs r0, 0x3\n"
	"\tstrh r0, [r4]\n"
	"\tldr r0, _0800C140\n"
	"\tbl m4aMPlayStop\n"
	"\tldrh r0, [r6]\n"
	"\tbl m4aSongNumStart\n"
	"\tb _0800C15E\n"
	"\t.align 2, 0\n"
"_0800C140: .4byte gUnknown_20008F0\n"
"_0800C144:\n"
	"\tsubs r0, 0x1\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tcmp r0, 0x1\n"
	"\tbls _0800C15E\n"
	"\tldr r0, _0800C17C\n"
	"\tbl m4aMPlayStop\n"
	"\tldrh r0, [r6]\n"
	"\tbl m4aSongNumStart\n"
	"\tmovs r0, 0x3\n"
"_0800C15C:\n"
	"\tstrh r0, [r4]\n"
"_0800C15E:\n"
	"\tldr r0, _0800C180\n"
	"\tldrh r0, [r0]\n"
	"\tcmp r0, 0x26\n"
	"\tbgt _0800C184\n"
	"\tcmp r0, 0x25\n"
	"\tbge _0800C19A\n"
	"\tcmp r0, 0x1A\n"
	"\tblt _0800C1A0\n"
	"\tcmp r0, 0x1F\n"
	"\tble _0800C19A\n"
	"\tcmp r0, 0x23\n"
	"\tbgt _0800C1A0\n"
	"\tcmp r0, 0x22\n"
	"\tblt _0800C1A0\n"
	"\tb _0800C19A\n"
	"\t.align 2, 0\n"
"_0800C17C: .4byte gUnknown_20008F0\n"
"_0800C180: .4byte gCurrentBGSong\n"
"_0800C184:\n"
	"\tcmp r0, 0x7A\n"
	"\tbeq _0800C19A\n"
	"\tcmp r0, 0x7A\n"
	"\tbgt _0800C196\n"
	"\tcmp r0, 0x77\n"
	"\tbgt _0800C1A0\n"
	"\tcmp r0, 0x75\n"
	"\tblt _0800C1A0\n"
	"\tb _0800C19A\n"
"_0800C196:\n"
	"\tcmp r0, 0x7F\n"
	"\tbne _0800C1A0\n"
"_0800C19A:\n"
	"\tldr r1, _0800C1AC\n"
	"\tmovs r0, 0x1\n"
	"\tstrb r0, [r1]\n"
"_0800C1A0:\n"
	"\tmov r0, r8\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800C208\n"
	"\tbl EnableInterrupts\n"
	"\tb _0800C208\n"
	"\t.align 2, 0\n"
"_0800C1AC: .4byte gUnknown_202D694\n"
"_0800C1B0:\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_800CAAC\n"
	"\tlsls r0, 24\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800C208\n"
	"\tadds r0, r5, 0\n"
	"\tbl sub_800CAE0\n"
	"\tlsls r0, 16\n"
	"\tlsrs r0, 16\n"
	"\tlsls r2, r0, 3\n"
	"\tldr r1, _0800C1D8\n"
	"\tadds r4, r2, r1\n"
	"\tcmp r0, 0x1\n"
	"\tbhi _0800C1DC\n"
"_0800C1D0:\n"
	"\tadds r0, r5, 0\n"
	"\tbl nullsub_20\n"
	"\tb _0800C208\n"
	"\t.align 2, 0\n"
"_0800C1D8: .4byte gUnknown_3000FD8\n"
"_0800C1DC:\n"
	"\tbl DisableInterrupts\n"
	"\tlsls r0, 24\n"
	"\tlsrs r5, r0, 24\n"
	"\tmov r0, r8\n"
	"\tbl m4aSongNumStart\n"
	"\tmovs r0, 0x1\n"
	"\tstrh r0, [r4]\n"
	"\tmov r0, r8\n"
	"\tstrh r0, [r4, 0x2]\n"
	"\tcmp r6, r7\n"
	"\tbne _0800C1FA\n"
	"\tmovs r0, 0\n"
	"\tb _0800C1FC\n"
"_0800C1FA:\n"
	"\tmovs r0, 0x1\n"
"_0800C1FC:\n"
	"\tstrb r0, [r4, 0x6]\n"
	"\tstrh r6, [r4, 0x4]\n"
	"\tcmp r5, 0\n"
	"\tbeq _0800C208\n"
	"\tbl EnableInterrupts\n"
"_0800C208:\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0");
}
#endif

void sub_800C214(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  u16 msVar;
  struct MusicPlayerInfo *info;
  struct unkStruct_3000FD8 *preload;

  if (256 < volume) {
    volume = 256;
  }

  if ((!sub_800CACC(songIndex)) && (sub_800CAAC(songIndex))) {
    msVar = sub_800CAE0(songIndex);
    info = gMPlayTable[msVar].info;
    preload = &gUnknown_3000FD8[msVar];
    if (msVar > 1) {
      interrupt_flag = DisableInterrupts();
      if (preload->songIndex == songIndex) {
        m4aMPlayVolumeControl(info, 0xf, volume);
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
  }
}
