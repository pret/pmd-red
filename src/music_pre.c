#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"
#include "bg.h"
#include "music.h"
#include "input.h"

extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
extern void SoundBiasReset();
extern void SoundBiasSet();
extern void AckInterrupt(u16);
extern void nullsub_25();
extern void nullsub_18();
extern void UpdateSound();
extern void nullsub_21(u16);

typedef void (*IntrCallback)(void);
extern IntrCallback gIntrCallbacks[];

struct unkStruct_202D648
{
    s16 unk0;
    s16 unk2; // Vcount??
    IntrCallback unk4; // some function... just making it IntrCallback for now
};
extern struct unkStruct_202D648 gUnknown_202D648[8];
extern struct unkStruct_202D648 gUnknown_202D608[8];

extern struct MusicPlayerInfo gMPlayInfo_BGM; // BGM??
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

extern u32 gUnknown_203B0A0;
extern s16 gUnknown_203B0AA;
extern s16 gUnknown_203B0AC;
extern s16 gUnknown_203B0AE;
extern s16 gUnknown_203B0B0;
extern s16 gUnknown_203B0B2;

struct unkStruct_3000FD8
{
    u16 unk0;
    u16 songIndex;
    u16 unk4;
    u8 unk6;
};

extern struct unkStruct_3000FD8 gUnknown_3000FD8[8];
extern struct unkStruct_3000FD8 gUnknown_3000FE8[8];

extern u8 gUnknown_202D7FE;
extern u16 gBldCnt;
extern struct BGControlStruct gBG0Control;
extern struct BGControlStruct gBG1Control;
extern struct BGControlStruct gBG2Control;
extern struct BGControlStruct gBG3Control;

enum
{
    BG0,
    BG1,
    BG2,
    BG3,
    NUM_BGS
};

extern void SoundVSync();
extern void BlinkSavingIcon();

void sub_800BF80(void);
void xxx_update_bg_sound_input(void);

void UnusedIntrFunc(void)
{
}

void VBlankIntr(void)
{
    int index;

    gUnknown_203B0A0++;
    SoundVSync();
    BlinkSavingIcon();
    if (gIntrCallbacks[1] != NULL) {
        gIntrCallbacks[1]();
    }
    for(index = 0; index < gUnknown_203B0AA; index++) {
        gUnknown_202D648[index] = gUnknown_202D608[index];
    }
    gUnknown_203B0AC = gUnknown_203B0AA;
    gUnknown_203B0AE = -1;
    gUnknown_203B0B0 = -1;
    gUnknown_203B0B2 = -1;
    REG_DISPSTAT = DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;
    if (gUnknown_203B099 == 0) {
        UpdateSound();
    }
    AckInterrupt(INTR_FLAG_VBLANK);
}

// Registers are a little off.. seems to be around the while loop
#ifdef NONMATCHING
void VCountIntr(void)
{
  s32 sVar1;
  s32 sVar2;
  
  // Hack to get the lsr/asr shifts
  sVar2 = REG_VCOUNT << 16;
  sVar2 = sVar2 >> 16;

  if (gUnknown_203B0AE < 0) {
    if (gIntrCallbacks[2] != 0) {
      gIntrCallbacks[2]();
    }
    gUnknown_203B0AE = 0;
  }
  if (gUnknown_203B0AE < gUnknown_203B0AC) {
    sVar1 = gUnknown_202D648[gUnknown_203B0AE].unk2;
    while (sVar1 <= sVar2) {
      if ( gUnknown_202D648[gUnknown_203B0AE].unk4 != NULL) {
        gUnknown_202D648[gUnknown_203B0AE].unk4();
      }
      gUnknown_203B0AE++;
      if (gUnknown_203B0AC >= gUnknown_203B0AE) break;
      sVar1 = gUnknown_202D648[gUnknown_203B0AE].unk2;
    }
    if (gUnknown_203B0AE < gUnknown_203B0AC) {
      REG_DISPSTAT = gUnknown_202D648[gUnknown_203B0AE].unk2 << 8 | DISPSTAT_VBLANK_INTR | DISPSTAT_VCOUNT_INTR;
    }
  }
  AckInterrupt(INTR_FLAG_VCOUNT);
}
#else
NAKED
void VCountIntr(void)
{
    asm_unified(
	"\tpush {r4-r7,lr}\n"
	"\tmov r7, r8\n"
	"\tpush {r7}\n"
	"\tldr r0, _0800BA44\n"
	"\tldrh r0, [r0]\n"
	"\tlsls r0, 16\n"
	"\tasrs r6, r0, 16\n"
	"\tldr r0, _0800BA48\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r0, r2]\n"
	"\tadds r7, r0, 0\n"
	"\tcmp r1, 0\n"
	"\tbge _0800B9B2\n"
	"\tldr r0, _0800BA4C\n"
	"\tldr r0, [r0, 0x8]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800B9AE\n"
	"\tbl _call_via_r0\n"
"_0800B9AE:\n"
	"\tmovs r0, 0\n"
	"\tstrh r0, [r7]\n"
"_0800B9B2:\n"
	"\tldr r0, _0800BA50\n"
	"\tmovs r3, 0\n"
	"\tldrsh r2, [r7, r3]\n"
	"\tmovs r3, 0\n"
	"\tldrsh r1, [r0, r3]\n"
	"\tmov r8, r0\n"
	"\tcmp r2, r1\n"
	"\tbge _0800BA34\n"
	"\tldr r1, _0800BA54\n"
	"\tadds r0, r2, 0\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tmovs r3, 0x2\n"
	"\tldrsh r0, [r0, r3]\n"
	"\tcmp r0, r6\n"
	"\tbgt _0800BA10\n"
	"\tadds r5, r1, 0\n"
	"\tadds r4, r7, 0\n"
"_0800B9D6:\n"
	"\tmovs r1, 0\n"
	"\tldrsh r0, [r4, r1]\n"
	"\tlsls r0, 3\n"
	"\tadds r1, r5, 0x4\n"
	"\tadds r0, r1\n"
	"\tldr r0, [r0]\n"
	"\tcmp r0, 0\n"
	"\tbeq _0800B9EA\n"
	"\tbl _call_via_r0\n"
"_0800B9EA:\n"
	"\tldrh r0, [r4]\n"
	"\tadds r0, 0x1\n"
	"\tstrh r0, [r4]\n"
	"\tldr r1, _0800BA50\n"
	"\tlsls r0, 16\n"
	"\tasrs r0, 16\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r1, r2]\n"
	"\tcmp r0, r1\n"
	"\tbge _0800BA34\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r4, r3]\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r5\n"
	"\tmovs r1, 0x2\n"
	"\tldrsh r0, [r0, r1]\n"
	"\tldr r7, _0800BA48\n"
	"\tcmp r0, r6\n"
	"\tble _0800B9D6\n"
"_0800BA10:\n"
	"\tmovs r2, 0\n"
	"\tldrsh r1, [r7, r2]\n"
	"\tmov r3, r8\n"
	"\tmovs r2, 0\n"
	"\tldrsh r0, [r3, r2]\n"
	"\tcmp r1, r0\n"
	"\tbge _0800BA34\n"
	"\tldr r2, _0800BA58\n"
	"\tldr r1, _0800BA54\n"
	"\tmovs r3, 0\n"
	"\tldrsh r0, [r7, r3]\n"
	"\tlsls r0, 3\n"
	"\tadds r0, r1\n"
	"\tldrh r0, [r0, 0x2]\n"
	"\tlsls r0, 8\n"
	"\tmovs r1, 0x28\n"
	"\torrs r0, r1\n"
	"\tstrh r0, [r2]\n"
"_0800BA34:\n"
	"\tmovs r0, 0x4\n"
	"\tbl AckInterrupt\n"
	"\tpop {r3}\n"
	"\tmov r8, r3\n"
	"\tpop {r4-r7}\n"
	"\tpop {r0}\n"
	"\tbx r0\n"
	"\t.align 2, 0\n"
"_0800BA44: .4byte 0x04000006\n"
"_0800BA48: .4byte gUnknown_203B0AE\n"
"_0800BA4C: .4byte gIntrCallbacks\n"
"_0800BA50: .4byte gUnknown_203B0AC\n"
"_0800BA54: .4byte gUnknown_202D648\n"
"_0800BA58: .4byte 0x04000004"
    );
}
#endif

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

void xxx_update_bg_sound_input(void)
{
    if(gUnknown_203B09B != 0){
        gUnknown_203B09C++;
    }
    else {
        gUnknown_203B09B = 1;
        gUnknown_203B09A = 0;
        gUnknown_203B09C = 0;
        UpdateBGControlRegisters();
        if(gUnknown_203B099 != 0)
            UpdateSound();
        UpdateInput();
        gUnknown_203B099 = 0;
        gUnknown_203B0A4 = gUnknown_203B0A0;
    }
}

void Timer3Intr(void)
{
    if(gIntrCallbacks[4])
        gIntrCallbacks[4]();
    AckInterrupt(INTR_FLAG_TIMER3);
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

    while(REG_KEYINPUT != KEYS_MASK){}

    interrupt_flag = DisableInterrupts();

    while(REG_VCOUNT < 160){}

    dispcnt_store = REG_DISPCNT;
    REG_DISPCNT = DISPCNT_FORCED_BLANK;

    *(vu16 *)BG_PLTT = RGB_WHITE;

    ie_store = REG_IE;
    REG_IE = INTR_FLAG_KEYPAD | INTR_FLAG_GAMEPAK;

    REG_KEYCNT = KEY_AND_INTR | R_BUTTON | L_BUTTON | SELECT_BUTTON; // 0x8304
    REG_IME = 1;

    SoundBiasReset();
    asm("swi 0x3");
    SoundBiasSet();

    REG_IME = 0;
    REG_IE = ie_store;
    REG_KEYCNT = 0;
    REG_DISPCNT = dispcnt_store;
    *(vu16 *)BG_PLTT = RGB_BLACK;

    if(interrupt_flag)
        EnableInterrupts();
    while(REG_KEYINPUT != KEYS_MASK){}
}

void nullsub_17(void)
{
}

void UpdateBGControlRegisters(void)
{
    u32 BGCNT_Priority[NUM_BGS];

    if(gUnknown_202D7FE == 1)
    {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }
    else
    {
        BGCNT_Priority[BG0] = BGCNT_PRIORITY(0);
        BGCNT_Priority[BG1] = BGCNT_PRIORITY(1);
        BGCNT_Priority[BG2] = BGCNT_PRIORITY(2);
        BGCNT_Priority[BG3] = BGCNT_PRIORITY(3);
    }

    REG_BG0HOFS = gBG0Control.hofs;
    REG_BG0VOFS = gBG0Control.vofs;
    REG_BG1HOFS = gBG1Control.hofs;
    REG_BG1VOFS = gBG1Control.vofs;
    REG_BG2HOFS = gBG2Control.hofs;
    REG_BG2VOFS = gBG2Control.vofs;
    REG_BG3HOFS = gBG3Control.hofs;
    REG_BG3VOFS = gBG3Control.vofs;

    REG_BG0CNT = BGCNT_Priority[BG0] | BGCNT_SCREENBASE(12) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2C00
    REG_BG1CNT = BGCNT_Priority[BG1] | BGCNT_SCREENBASE(13) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2D00
    if(gBG2Control.unk2 == 0x8000)
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(2) | BGCNT_WRAP; // 0x2E08
    else
        REG_BG2CNT = BGCNT_Priority[BG2] | BGCNT_SCREENBASE(14) | BGCNT_CHARBASE(0) | BGCNT_WRAP; // 0x2E00
    REG_BG3CNT = BGCNT_Priority[BG3] | BGCNT_SCREENBASE(15) | BGCNT_CHARBASE(2) | BGCNT_WRAP;
    REG_BLDCNT = gBldCnt;
}

void InitMusic(void)
{
    s32 counter;

    struct unkStruct_3000FD8 *preload;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    m4aSoundInit();

    gBGMusicPlayerState = 0;
    gCurrentBGSong = 999;
    gUnknown_202D68C = 999;
    gUnknown_202D68E = 997;
    gUnknown_202D690 = 0;
    gUnknown_202D692 = 0;
    gUnknown_202D694 = 0;

    for(counter = 0, preload = &gUnknown_3000FD8[0]; counter < 8; counter++, preload++)
    {
        preload->unk0 = 0;
        preload->songIndex = 997;
        preload->unk4 = 0;
        preload->unk6 = 0;
    }
    nullsub_19();
}

void sub_800BDDC(void)
{
    sub_800BF80();
    sub_800C298(998);
    sub_800C298(997);
}


void StartNewBGM(u16 songIndex)
{
    bool8 interrupt_flag;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == 999)
        return;
    if(songIndex == gCurrentBGSong)
    {
        if((u16)(gBGMusicPlayerState - 1) <= 1)
            return;
    }
    if(GetMusicPlayerIndex(songIndex))
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

    if(!IsBGSong(SongIndex))
        return;
    if(SongIndex == 999)
        return;
    if(SongIndex == gCurrentBGSong)
    {
        if((u16)(gBGMusicPlayerState - 1) <= 1)
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
        m4aMPlayImmInit(&gMPlayInfo_BGM);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0);
        m4aSongNumStop(SongIndex);
        m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
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
            m4aMPlayStop(&gMPlayInfo_BGM);
        }
    }
    gCurrentBGSong = 999;
    gUnknown_202D68C = 999;
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeOutBGM(u16 speed)
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
                m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
            }
            else
            {
                gCurrentBGSong = 999;
                m4aMPlayStop(&gMPlayInfo_BGM);
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

void sub_800C074(u16 SongIndex, u16 param_2)
{
  bool8 interrupt_flag;
  bool8 interrupt_flag2;
  u16 msVar;
  struct unkStruct_3000FD8 *preload;

  if (SongIndex == 997)
    return;
  if (param_2 > 256)
    param_2 = 256;

  if (IsFanfare(SongIndex)) 
  {
    if (GetMusicPlayerIndex(SongIndex) == 1) {
      interrupt_flag = DisableInterrupts();
      gUnknown_202D68E = SongIndex;
      if(gUnknown_202D690 == 0)
      {
        if (gCurrentBGSong != 999) 
        {
            if ((u16)(gBGMusicPlayerState - 1) < 2)
            {
                gUnknown_202D690 = 1;
                gUnknown_202D692 = 16;
                gUnknown_202D694 = 0;
                m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, 1);
            }
            else if (gBGMusicPlayerState == 3)
                gUnknown_202D690 = 2;
            else
            {
                gUnknown_202D690 = 3;
                m4aMPlayStop(&gMPlayInfo_BGM);
                m4aSongNumStart(gUnknown_202D68E);
            }
        }
        else
        {
            gUnknown_202D690 = 3;
            m4aMPlayStop(&gMPlayInfo_BGM);
            m4aSongNumStart(gUnknown_202D68E);
        }
      }
      else
      {
        if (1 < (u16)(gUnknown_202D690 - 1)) 
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
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
    if (!IsSoundEffect(SongIndex))
      return;
    msVar = GetMusicPlayerIndex(SongIndex);
    preload = &gUnknown_3000FD8[msVar]; // need to load this before comparison to match
    if (msVar <= 1)
        nullsub_20(SongIndex);
    else
    {
      interrupt_flag2 = DisableInterrupts();
      m4aSongNumStart(SongIndex);
      preload->unk0 = 1;
      preload->songIndex = SongIndex;
      if(param_2 == 256)
      {
        preload->unk6 = 0;
      }
      else
      {
        preload->unk6 = 1;
      }
      preload->unk4 = param_2;
      if (interrupt_flag2)
        EnableInterrupts();
    }
  }
}

void sub_800C214(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  u16 msVar;
  struct MusicPlayerInfo *info;
  struct unkStruct_3000FD8 *preload;

  if (256 < volume) {
    volume = 256;
  }

  if ((!IsFanfare(songIndex)) && (IsSoundEffect(songIndex))) {
    msVar = GetMusicPlayerIndex(songIndex);
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

void sub_800C298(u16 songIndex)
{
    // Each section needs a var for interrupts..
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;

    u32 uVar2;
    int iVar4;
    struct MusicPlayerInfo *puVar6;
    struct unkStruct_3000FD8 *preload;
    struct unkStruct_3000FD8 *puVar3;

    if (songIndex == 997) {
        cVar1 = DisableInterrupts();

        for(iVar4 = 2, puVar3 = &gUnknown_3000FE8[0]; iVar4 < 7; iVar4++, puVar3++)
        {
            m4aMPlayStop(gMPlayTable[iVar4].info);
            puVar3->unk0 = 0;
            puVar3->songIndex = 997;
            puVar3->unk4 = 0;
            puVar3->unk6 = 0;
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsSoundEffect(songIndex))
    {
        uVar2 = GetMusicPlayerIndex(songIndex);
        puVar6 = gMPlayTable[uVar2].info;
        preload = &gUnknown_3000FD8[uVar2];
        if (uVar2 < 2) {
            nullsub_21(songIndex);
        }
        else {
            cVar2 = DisableInterrupts();
            if (preload->songIndex == songIndex) {
                m4aMPlayStop(puVar6);
                preload->unk0 = 0;
                preload->songIndex = 997;
                preload->unk4 = 0;
                preload->unk6 = 0;
            }
            if (cVar2 != '\0') {
                EnableInterrupts();
            }
        }
    }
    else if (songIndex == 998)
    {
        cVar3 = DisableInterrupts();
        if (gUnknown_202D690 != 0) {
            if (gUnknown_202D68E != 997) {
                gUnknown_202D68E = 997;
                m4aMPlayStop(&gUnknown_2000970);
            }
        }
        if (cVar3 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsFanfare(songIndex))
    {
        cVar4 = DisableInterrupts();
        if (gUnknown_202D690 != 0) {
            if (gUnknown_202D68E == songIndex) {
                gUnknown_202D68E = 997;
                m4aMPlayStop(&gUnknown_2000970);
            }
        }
        if (cVar4 != '\0') {
            EnableInterrupts();
        }
    }
}

void sub_800C3F8(u16 songIndex, u16 speed)
{
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;
    u32 comparison;
    s32 uVar6;
    u32 uVar8;
    struct unkStruct_3000FD8 *preload;
    struct unkStruct_3000FD8 *puVar3;
    struct MusicPlayerInfo *puVar5;

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

    if (songIndex == 997) {
        cVar1 = DisableInterrupts();
        for(uVar6 = 2, puVar3 = &gUnknown_3000FE8[0]; uVar6 < 7; uVar6++, puVar3++)
        {
            if (puVar3->songIndex != 997) {
                if (sub_800CAF0(uVar6) != '\0') {
                    m4aMPlayFadeOut(gMPlayTable[uVar6].info,speed);
                }
                else {
                    m4aMPlayStop(gMPlayTable[uVar6].info);
                    puVar3->unk0 = 0;
                    puVar3->songIndex = 997;
                    puVar3->unk4 = 0;
                    puVar3->unk6 = 0;
                }
            }
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else {
        if (IsSoundEffect(songIndex)) {
            uVar8 = GetMusicPlayerIndex(songIndex);
            preload = &gUnknown_3000FD8[uVar8];
            puVar5 = gMPlayTable[uVar8].info;
            cVar2 = DisableInterrupts();
            if (preload->songIndex != 997) {
                if (sub_800CAF0(uVar8) != '\0') {
                    m4aMPlayFadeOut(puVar5,speed);
                }
                else {
                    m4aMPlayStop(puVar5);
                    preload->unk0 = 0;
                    preload->songIndex = 997;
                    preload->unk4 = 0;
                    preload->unk6 = 0;
                }
            }
            if (cVar2 != '\0') {
                EnableInterrupts();
            }
        }
        else if (songIndex == 998) {
            cVar3 = DisableInterrupts();
            if ((gUnknown_202D690 != 0) && (gUnknown_202D68E != 997)) {
                if (sub_800CAF0(1) != '\0') {
                    m4aMPlayFadeOut(&gUnknown_2000970,speed);
                }
                else {
                    m4aMPlayStop(&gUnknown_2000970);
                    gUnknown_202D68E = 997;
                }
            }
            if (cVar3 != '\0') {
                EnableInterrupts();
            }
        }
        else if (IsFanfare(songIndex)) {
            cVar4 = DisableInterrupts();
            if ((gUnknown_202D690 != 0) && (gUnknown_202D68E == songIndex)) {
                if (sub_800CAF0(1) != '\0') {
                    m4aMPlayFadeOut(&gUnknown_2000970,speed);
                }
                else {
                    m4aMPlayStop(&gUnknown_2000970);
                    gUnknown_202D68E = 997;
                }
            }
            if (cVar4 != '\0') {
                EnableInterrupts();
            }
        }
    }
}

bool8 sub_800C5D0(u16 songIndex)
{
  u32 uVar3;
  struct unkStruct_3000FD8 *preload;
  register u32 songIndex_u32 asm("r4");
  register u32 songIndex_u32_2 asm("r5");

  songIndex_u32 = songIndex;
  songIndex_u32_2 = songIndex_u32;
  

  if (IsFanfare(songIndex_u32)) {
    if ((gUnknown_202D690 != 0) && (gUnknown_202D68E == songIndex_u32)) {
      return TRUE;
    }
  }
  else
  {
    if (IsSoundEffect(songIndex_u32)) {
      uVar3 = GetMusicPlayerIndex(songIndex_u32);
      preload = &gUnknown_3000FD8[uVar3];
      if ((1 < uVar3) && (preload->songIndex == songIndex_u32_2)) {
        return TRUE;
      }
    }
  }
  return FALSE;
}

void SoundVSync(void)
{
  u8 cVar1;

  cVar1 = DisableInterrupts();
  m4aSoundVSync();
  if(cVar1)
    EnableInterrupts();
}


void nullsub_18(void)
{
}
