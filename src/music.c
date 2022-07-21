#include "global.h"
#include "gba/io_reg.h"
#include "m4a.h"
#include "bg.h"
#include "music.h"
#include "input.h"
#include "constants/bg_music.h"

extern bool8 EnableInterrupts(void);
extern bool8 DisableInterrupts(void);
extern void SoundBiasReset();
extern void SoundBiasSet();
extern void AckInterrupt(u16);
extern void nullsub_25(void);
void nullsub_18(void);
void UpdateSound(void);
void nullsub_21(u16);

extern void Random();
extern void sub_800BA5C();
void xxx_update_bg_sound_input();


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
extern u32 gUnknown_203B0A4;
extern u16 gBGMusicPlayerState;
extern u16 gCurrentBGSong;
extern u16 gQueuedBGSong;
extern u16 gCurrentFanfareSong;
extern u16 gFanfareMusicPlayerState;
extern u16 gMusicTransitionCounter;
extern bool8 gRestartBGM;
extern u8 gUnknown_203B099;
extern u8 gUnknown_203B09B;
extern u32 gUnknown_203B09C;
extern u8 gUnknown_203B09A;
extern u32 gUnknown_203B0B8;
extern u16 gRawKeyInput;

extern u32 gUnknown_203B0A0;
extern s16 gUnknown_203B0AA;
extern s16 gUnknown_203B0AC;
extern s16 gUnknown_203B0AE;
extern s16 gUnknown_203B0B0;
extern s16 gUnknown_203B0B2;

// PMD keeps it's own copy of music players for some reason
struct PMDMusicPlayer
{
    u16 unk0;
    u16 songIndex;
    u16 volume;
    bool8 unk6;
};

extern struct PMDMusicPlayer gUnknown_3000FD8[8];
extern struct PMDMusicPlayer gUnknown_3000FE8[8];

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

void SoundVSync();
extern void BlinkSavingIcon();

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
    s32 playerIndex;

    struct PMDMusicPlayer *musicPlayer;

    DmaStop(0);
    DmaStop(1);
    DmaStop(2);
    DmaStop(3);

    m4aSoundInit();

    gBGMusicPlayerState = 0;
    gCurrentBGSong = STOP_BGM;
    gQueuedBGSong = STOP_BGM;
    gCurrentFanfareSong = STOP_SOUND_EFFECT;
    gFanfareMusicPlayerState = 0;
    gMusicTransitionCounter = 0;
    gRestartBGM = FALSE;

    for(playerIndex = INDEX_BGM, musicPlayer = &gUnknown_3000FD8[0]; playerIndex < INDEX_SE6 + 1; playerIndex++, musicPlayer++)
    {
        musicPlayer->unk0 = 0;
        musicPlayer->songIndex = STOP_SOUND_EFFECT;
        musicPlayer->volume = 0;
        musicPlayer->unk6 = FALSE;
    }
    nullsub_19();
}

void StopAllMusic(void)
{
    StopBGM();
    StopFanfareSE(STOP_FANFARE);
    StopFanfareSE(STOP_SOUND_EFFECT);
}

void StartNewBGM(u16 songIndex)
{
    bool8 interrupt_flag;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == STOP_BGM)
        return;
    if(songIndex == gCurrentBGSong)
    {
        if((u16)(gBGMusicPlayerState - 1) <= 1)
            return;
    }
    if(GetMusicPlayerIndex(songIndex) != INDEX_BGM)
    {
        nullsub_20(songIndex);
        return;
    }
    interrupt_flag = DisableInterrupts();
    gCurrentBGSong = songIndex;
    gRestartBGM = TRUE;

    if(gFanfareMusicPlayerState == 0)
    {
        gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeInNewBGM(u16 songIndex, u16 speed)
{
    bool8 interrupt_flag;

    if(!IsBGSong(songIndex))
        return;
    if(songIndex == STOP_BGM)
        return;
    if(songIndex == gCurrentBGSong)
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
    gCurrentBGSong = songIndex;
    gRestartBGM = TRUE;

    if(gFanfareMusicPlayerState == 0)
    {
        gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
        m4aSongNumStart(songIndex);
        m4aMPlayImmInit(&gMPlayInfo_BGM);
        m4aMPlayVolumeControl(&gMPlayInfo_BGM, 0xFF, 0);
        m4aSongNumStop(songIndex);
        m4aMPlayFadeIn(&gMPlayInfo_BGM, speed);
    }
    if(interrupt_flag)
        EnableInterrupts();
}

void QueueBGM(u16 songIndex)
{
    if(gCurrentBGSong == STOP_BGM)
    {
        StartNewBGM(songIndex);
        gQueuedBGSong = STOP_BGM;
    }
    else
        gQueuedBGSong = songIndex;
}

void StopBGM(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
        }
    }
    gCurrentBGSong = STOP_BGM;
    gQueuedBGSong = STOP_BGM;
    if(interrupt_flag)
        EnableInterrupts();
}

void FadeOutBGM(u16 speed)
{
    bool8 interrupt_flag;

    if(speed > ((0x80 << 17) / 65536))
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
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            if(gBGMusicPlayerState == 2)
            {
                gBGMusicPlayerState = 3;
                m4aMPlayFadeOut(&gMPlayInfo_BGM, speed);
            }
            else
            {
                gCurrentBGSong = STOP_BGM;
                m4aMPlayStop(&gMPlayInfo_BGM);
            }
        }
    }
    else
    {
        gCurrentBGSong = STOP_BGM;
    }
    gQueuedBGSong = STOP_BGM;
    if(interrupt_flag)
        EnableInterrupts();
}

u16 GetCurrentBGSong(void)
{
    return gCurrentBGSong;
}

void PlayFanfareSE(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  bool8 interrupt_flag2;
  u16 playerIndex;
  struct PMDMusicPlayer *musicPlayer;

  if (songIndex == STOP_SOUND_EFFECT)
    return;
  if (volume > MAX_VOLUME)
    volume = MAX_VOLUME;

  if (IsFanfare(songIndex)) 
  {
    if (GetMusicPlayerIndex(songIndex) == INDEX_FANFARE) {
      interrupt_flag = DisableInterrupts();
      gCurrentFanfareSong = songIndex;
      if(gFanfareMusicPlayerState == 0)
      {
        if (gCurrentBGSong != STOP_BGM) 
        {
            if ((u16)(gBGMusicPlayerState - 1) < 2)
            {
                gFanfareMusicPlayerState = 1;
                gMusicTransitionCounter = 16;
                gRestartBGM = FALSE;
                m4aMPlayFadeOutTemporarily(&gMPlayInfo_BGM, 1);
            }
            else if (gBGMusicPlayerState == 3)
                gFanfareMusicPlayerState = 2;
            else
            {
                gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                m4aMPlayStop(&gMPlayInfo_BGM);
                m4aSongNumStart(gCurrentFanfareSong);
            }
        }
        else
        {
            gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
            m4aMPlayStop(&gMPlayInfo_BGM);
            m4aSongNumStart(gCurrentFanfareSong);
        }
      }
      else
      {
        if (1 < (u16)(gFanfareMusicPlayerState - 1)) 
        {
            m4aMPlayStop(&gMPlayInfo_BGM);
            m4aSongNumStart(gCurrentFanfareSong);
            gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
        }
      }
      switch(gCurrentBGSong)
      {
        case MUS_RAYQUAZAS_DOMAIN:
        case MUS_FRIEND_AREA_STRATOS_LOOKOUT:
        case MUS_FRIEND_AREA_RAINBOW_PEAK:
        case MUS_DREAM_EATER:
        case MUS_FRIEND_AREA_DEEPSEA_CURRENT:
        case MUS_FRIEND_AREA_SEAFLOOR_CAVE:
        case MUS_FRIEND_AREA_VOLCANIC_PIT:
        case MUS_FRIEND_AREA_CRYPTIC_CAVE:
        case MUS_THE_OTHER_SIDE:
        case MUS_THE_MOUNTAIN_OF_FIRE:
        case MUS_FRIEND_AREA_LEGENDARY_ISLAND:
        case MUS_FRIEND_AREA_SOUTHERN_ISLAND:
        case MUS_FRIEND_AREA_ENCLOSED_ISLAND:
        case MUS_FRIEND_AREA_FINAL_ISLAND:
        case MUS_FRIEND_AREA_HEALING_FOREST:
            gRestartBGM = TRUE;
            break;
        default:
            break;
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
    else
    {
        nullsub_20(songIndex);
    }
  }
  else
  {
    if (!IsSoundEffect(songIndex))
      return;
    playerIndex = GetMusicPlayerIndex(songIndex);
    musicPlayer = &gUnknown_3000FD8[playerIndex]; // need to load this before comparison to match
    if (playerIndex < INDEX_SE1)
        nullsub_20(songIndex);
    else
    {
      interrupt_flag2 = DisableInterrupts();
      m4aSongNumStart(songIndex);
      musicPlayer->unk0 = 1;
      musicPlayer->songIndex = songIndex;
      if(volume == MAX_VOLUME)
      {
        musicPlayer->unk6 = FALSE;
      }
      else
      {
        musicPlayer->unk6 = TRUE;
      }
      musicPlayer->volume = volume;
      if (interrupt_flag2)
        EnableInterrupts();
    }
  }
}

void SetSoundEffectVolume(u16 songIndex, u16 volume)
{
  bool8 interrupt_flag;
  u16 playerIndex;
  struct MusicPlayerInfo *info;
  struct PMDMusicPlayer *musicPlayer;

  if (MAX_VOLUME < volume) {
    volume = MAX_VOLUME;
  }

  if ((!IsFanfare(songIndex)) && (IsSoundEffect(songIndex))) {
    playerIndex = GetMusicPlayerIndex(songIndex);
    info = gMPlayTable[playerIndex].info;
    musicPlayer = &gUnknown_3000FD8[playerIndex];
    if (playerIndex >= INDEX_SE1) {
      interrupt_flag = DisableInterrupts();
      if (musicPlayer->songIndex == songIndex) {
        m4aMPlayVolumeControl(info, 0xf, volume);
      }
      if (interrupt_flag)
        EnableInterrupts();
    }
  }
}

void StopFanfareSE(u16 songIndex)
{
    // Each section needs a var for interrupts..
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;

    u32 playerIndex;
    s32 playerIndex2;
    struct MusicPlayerInfo *info;
    struct PMDMusicPlayer *musicPlayer;
    struct PMDMusicPlayer *musicPlayer1;

    if (songIndex == STOP_SOUND_EFFECT) {
        cVar1 = DisableInterrupts();

        for(playerIndex2 = INDEX_SE1, musicPlayer1 = &gUnknown_3000FE8[0]; playerIndex2 < INDEX_SE6; playerIndex2++, musicPlayer1++)
        {
            m4aMPlayStop(gMPlayTable[playerIndex2].info);
            musicPlayer1->unk0 = 0;
            musicPlayer1->songIndex = STOP_SOUND_EFFECT;
            musicPlayer1->volume = 0;
            musicPlayer1->unk6 = FALSE;
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsSoundEffect(songIndex))
    {
        playerIndex = GetMusicPlayerIndex(songIndex);
        info = gMPlayTable[playerIndex].info;
        musicPlayer = &gUnknown_3000FD8[playerIndex];
        if (playerIndex < INDEX_SE1) {
            nullsub_21(songIndex);
        }
        else {
            cVar2 = DisableInterrupts();
            if (musicPlayer->songIndex == songIndex) {
                m4aMPlayStop(info);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->unk6 = FALSE;
            }
            if (cVar2 != '\0') {
                EnableInterrupts();
            }
        }
    }
    else if (songIndex == STOP_FANFARE)
    {
        cVar3 = DisableInterrupts();
        if (gFanfareMusicPlayerState != 0) {
            if (gCurrentFanfareSong != STOP_SOUND_EFFECT) {
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }
        if (cVar3 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsFanfare(songIndex))
    {
        cVar4 = DisableInterrupts();
        if (gFanfareMusicPlayerState != 0) {
            if (gCurrentFanfareSong == songIndex) {
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                m4aMPlayStop(&gMPlayInfo_Fanfare);
            }
        }
        if (cVar4 != '\0') {
            EnableInterrupts();
        }
    }
}

void FadeOutFanfareSE(u16 songIndex, u16 speed)
{
    char cVar1;
    char cVar2;
    char cVar3;
    char cVar4;
    u32 comparison;
    s32 playerIndex2;
    u32 playerIndex;
    struct PMDMusicPlayer *musicPlayer;
    struct PMDMusicPlayer *musicPlayer1;
    struct MusicPlayerInfo *playerInfo;

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

    if (songIndex == STOP_SOUND_EFFECT) {
        cVar1 = DisableInterrupts();
        for(playerIndex2 = INDEX_SE1, musicPlayer1 = &gUnknown_3000FE8[0]; playerIndex2 < INDEX_SE6; playerIndex2++, musicPlayer1++)
        {
            if (musicPlayer1->songIndex != STOP_SOUND_EFFECT) {
                if (IsMusicPlayerPlaying(playerIndex2)) {
                    m4aMPlayFadeOut(gMPlayTable[playerIndex2].info,speed);
                }
                else {
                    m4aMPlayStop(gMPlayTable[playerIndex2].info);
                    musicPlayer1->unk0 = 0;
                    musicPlayer1->songIndex = STOP_SOUND_EFFECT;
                    musicPlayer1->volume = 0;
                    musicPlayer1->unk6 = FALSE;
                }
            }
        }
        if (cVar1 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsSoundEffect(songIndex)) {
        playerIndex = GetMusicPlayerIndex(songIndex);
        musicPlayer = &gUnknown_3000FD8[playerIndex];
        playerInfo = gMPlayTable[playerIndex].info;
        cVar2 = DisableInterrupts();
        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) {
            if (IsMusicPlayerPlaying(playerIndex)) {
                m4aMPlayFadeOut(playerInfo,speed);
            }
            else {
                m4aMPlayStop(playerInfo);
                musicPlayer->unk0 = 0;
                musicPlayer->songIndex = STOP_SOUND_EFFECT;
                musicPlayer->volume = 0;
                musicPlayer->unk6 = FALSE;
            }
        }
        if (cVar2 != '\0') {
            EnableInterrupts();
        }
    }
    else if (songIndex == STOP_FANFARE) {
        cVar3 = DisableInterrupts();
        if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong != STOP_SOUND_EFFECT)) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE)) {
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare,speed);
            }
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }
        if (cVar3 != '\0') {
            EnableInterrupts();
        }
    }
    else if (IsFanfare(songIndex)) {
        cVar4 = DisableInterrupts();
        if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong == songIndex)) {
            if (IsMusicPlayerPlaying(INDEX_FANFARE)) {
                m4aMPlayFadeOut(&gMPlayInfo_Fanfare,speed);
            }
            else {
                m4aMPlayStop(&gMPlayInfo_Fanfare);
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
            }
        }
        if (cVar4 != '\0') {
            EnableInterrupts();
        }
    }
}

bool8 IsFanfareSEPlaying(u16 songIndex)
{
  u32 playerIndex;
  struct PMDMusicPlayer *musicPlayer;
#ifndef NONMATCHING
  register u32 songIndex_u32 asm("r4");
  register u32 songIndex_u32_2 asm("r5");
#else
  u32 songIndex_u32;
  u32 songIndex_u32_2;
#endif

  songIndex_u32 = songIndex;
  songIndex_u32_2 = songIndex_u32;

  if (IsFanfare(songIndex_u32)) {
    if ((gFanfareMusicPlayerState != 0) && (gCurrentFanfareSong == songIndex_u32)) {
      return TRUE;
    }
  }
  else
  {
    if (IsSoundEffect(songIndex_u32)) {
      playerIndex = GetMusicPlayerIndex(songIndex_u32);
      musicPlayer = &gUnknown_3000FD8[playerIndex];
      if ((INDEX_SE1 <= playerIndex) && (musicPlayer->songIndex == songIndex_u32_2)) {
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

void UpdateSound(void)
{
    struct PMDMusicPlayer *musicPlayer; // r4
    s32 musicPlayerIndex; // r5
    
    m4aSoundMain();

    if(gFanfareMusicPlayerState != 0)
    {
        switch(gFanfareMusicPlayerState)
        {
            case 1:
                if (gMusicTransitionCounter != 0) 
                {
                    gMusicTransitionCounter--;
                }
                else if (gCurrentFanfareSong == STOP_SOUND_EFFECT) 
                {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                else
                {
                    m4aSongNumStart(gCurrentFanfareSong);
                    gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 2:
                if ((gCurrentBGSong != STOP_BGM) && (IsMusicPlayerPlaying(INDEX_BGM)))
                    break;
                if (gCurrentFanfareSong == STOP_SOUND_EFFECT)
                {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                else
                {
                    m4aSongNumStart(gCurrentFanfareSong);
                    gFanfareMusicPlayerState = FANFARE_PLAYER_STATE_PLAYING;
                }
                break;
            case 3:
                if ((gCurrentFanfareSong != STOP_SOUND_EFFECT) && (!IsMusicPlayerPlaying(INDEX_FANFARE))) // INDEX_FANFARE
                    break;
                else {
                    gFanfareMusicPlayerState = 4;
                    gMusicTransitionCounter = 32;
                }
                break;
            case 4:
                if (gCurrentFanfareSong != STOP_SOUND_EFFECT) 
                {
                    if (IsMusicPlayerPlaying(INDEX_FANFARE)) break; // INDEX_FANFARE
                }
                else
                    m4aMPlayStop(&gMPlayInfo_Fanfare);

                if (gMusicTransitionCounter != 0) 
                {
                    gMusicTransitionCounter--;
                    break;
                }
                else if (gCurrentBGSong != STOP_BGM) 
                {
                    gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                    if (gRestartBGM)
                        m4aSongNumStart(gCurrentBGSong);
                    else
                        m4aMPlayFadeIn(&gMPlayInfo_BGM,4);
                }
                else 
                {
                    gBGMusicPlayerState = 0;
                    m4aMPlayStop(&gMPlayInfo_BGM);
                }
                gFanfareMusicPlayerState = 0;
                gCurrentFanfareSong = STOP_SOUND_EFFECT;
                break;
        }
    }
    else if (gBGMusicPlayerState != BG_PLAYER_STATE_INITIALIZE)
    {
        switch(gBGMusicPlayerState)
        {

            case BG_PLAYER_STATE_PLAYING:
                if ((gCurrentBGSong == STOP_BGM) || IsMusicPlayerPlaying(INDEX_BGM)) // INDEX_BGM
                {
                    gBGMusicPlayerState = 2;
                }
                break;
            case 2:
            case 3:
                if (gCurrentBGSong != STOP_BGM) 
                {
                    if (IsMusicPlayerPlaying(INDEX_BGM)) break; // INDEX_BGM
                }
                else
                    m4aMPlayStop(&gMPlayInfo_BGM);
                gBGMusicPlayerState = 0;
                gCurrentBGSong = STOP_BGM;
                break;
            case BG_PLAYER_STATE_STOPPED: // can also be other constants
                break;
        }
    }
    else
    {
        if (!IsMusicPlayerPlaying(INDEX_BGM)) 
        {
#ifndef NONMATCHING
            register u16 r2 asm("r2") = gQueuedBGSong, r1 = r2;
#else
            u16 r2, r1;
            r2 = gQueuedBGSong, r1 = r2;
#endif
            if (r1 != STOP_BGM) 
            {
                gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                gCurrentBGSong = r2;
                m4aSongNumStart(r1);
                gQueuedBGSong = STOP_BGM;
            }
            else 
            {
                gBGMusicPlayerState = 0;
                gCurrentBGSong = STOP_BGM;
            }
        }
    }

    for(musicPlayerIndex = INDEX_SE1,  musicPlayer = &gUnknown_3000FE8[0]; musicPlayerIndex < INDEX_SE6; musicPlayerIndex++, musicPlayer++)
    {
        if (musicPlayer->songIndex != STOP_SOUND_EFFECT) 
        {
            switch(musicPlayer->unk0)
            {
                    case 1:
                        if ((musicPlayer->songIndex == STOP_BGM) || (IsMusicPlayerPlaying(musicPlayerIndex))) 
                        {
                            musicPlayer->unk0 = 2;
                        }
                        break;
                    case 2:
                        if (IsMusicPlayerPlaying(musicPlayerIndex))
                        {
                            if(musicPlayer->unk6)
                            {
                                musicPlayer->unk6 = FALSE;
                                m4aMPlayVolumeControl(gMPlayTable[musicPlayerIndex].info,0xff,musicPlayer->volume);
                            }
                        }
                        else 
                        {
                            musicPlayer->unk0 = 0;
                            musicPlayer->songIndex = STOP_SOUND_EFFECT;
                            musicPlayer->volume = 0;
                            musicPlayer->unk6 = FALSE;
                        }
                        break;
                    case 3:
                    case 0:
                        break;
            }
        }
    }
}

void StopBGMusicVSync(void)
{
    bool8 interrupt_flag;
    u16 temp;

    FadeOutFanfareSE(STOP_SOUND_EFFECT, 0x10);
    FadeOutFanfareSE(STOP_FANFARE, 0x10);

    interrupt_flag = DisableInterrupts();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            temp = gBGMusicPlayerState - 1;
            if(temp <= 1)
            {
                if(gBGMusicPlayerState == 2)
                {
                    gRestartBGM = FALSE;
                }
                else if(gBGMusicPlayerState == BG_PLAYER_STATE_PLAYING)
                {
                    gRestartBGM = TRUE;
                }
                gBGMusicPlayerState = BG_PLAYER_STATE_STOPPED;
            }
        }
    }
    m4aMPlayStop(&gMPlayInfo_BGM);
    m4aSoundVSyncOff();
    if(interrupt_flag)
    {
        EnableInterrupts();
    }
}

void StartBGMusicVSync(void)
{
    bool8 interrupt_flag = DisableInterrupts();
    m4aSoundVSyncOn();
    if(gFanfareMusicPlayerState == 0)
    {
        if(gCurrentBGSong != STOP_BGM)
        {
            if(gBGMusicPlayerState == BG_PLAYER_STATE_STOPPED)
            {
                gBGMusicPlayerState = BG_PLAYER_STATE_PLAYING;
                if(gRestartBGM)
                {
                    m4aSongNumStart(gCurrentBGSong);
                }
                else
                {
                    m4aMPlayContinue(&gMPlayInfo_BGM);
                }
            }
        }
    }
    if(interrupt_flag)
    {
        EnableInterrupts();
    }

}

void nullsub_179(void)
{
}

// Unused
bool8 IsValidSong(u32 songIndex)
{
    if(IsBGSong(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_BGM)
        {
            return TRUE;
        }
    }
    if(IsFanfare(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) == INDEX_FANFARE)
        {
            return TRUE;
        }
    }
    else if(IsSoundEffect(songIndex))
    {
        if(GetMusicPlayerIndex(songIndex) >= INDEX_SE1)
        {
            return TRUE;
        }
    }
    return FALSE;
}

void nullsub_19(void)
{
}

bool8 IsBGSong(u32 songIndex)
{
    if(songIndex <= NUM_BG_SONGS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsSoundEffect(u32 songIndex)
{
    if(songIndex - SOUND_EFFECTS_START_INDEX <= NUM_SOUND_EFFECTS)
    {
        return TRUE;
    }
    return FALSE;
}

bool8 IsFanfare(u32 songIndex)
{
    if(songIndex - FANFARE_START_INDEX <= NUM_FANFARES)
    {
        return TRUE;
    }
    return FALSE;
}

u16 GetMusicPlayerIndex(u16 songIndex)
{
    return gSongTable[songIndex].ms;
}

bool8 IsMusicPlayerPlaying(u16 playerIndex)
{
    // Had to cast this.. m4a_internal header has this as u32
    if((u16)gMPlayTable[playerIndex].info->status == 0)
    {
        return FALSE;
    }
    return TRUE;
}

void nullsub_20(u16 songIndex)
{
}

void nullsub_21(u16 songIndex)
{
}

void sub_800CB20(void)
{
    sub_800BA5C();
    gUnknown_203B0B8++;
    if((gRawKeyInput & (A_BUTTON | SELECT_BUTTON)) != 0)
    {
        Random();
    }
    Random();
}

// Unused
u32 sub_800CB50(void)
{
    return gUnknown_203B0B8;
}

void nullsub_180(void)
{
}

void xxx_call_update_bg_sound_input(void)
{
    xxx_update_bg_sound_input();
}

void nullsub_181(void)
{
}

u32 sub_800CB70(void)
{
    return 0;
}
