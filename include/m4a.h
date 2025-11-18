#ifndef GUARD_M4A_H
#define GUARD_M4A_H

#include "gba/m4a_internal.h"

void m4aSoundVSyncOn(void);
void m4aSoundVSyncOff(void);

void m4aSoundInit(void);
void m4aSoundMain(void);
void m4aSongNumStart(u16 n);
void m4aSongNumStartOrChange(u16 n);
void m4aSongNumStop(u16 n);
void m4aMPlayAllStop(void);
void m4aMPlayContinue(struct MusicPlayerInfo *mplayInfo);
void m4aMPlayFadeOut(struct MusicPlayerInfo *mplayInfo, u16 speed);
void m4aMPlayFadeOutTemporarily(struct MusicPlayerInfo *mplayInfo, u16 speed);
void m4aMPlayFadeIn(struct MusicPlayerInfo *mplayInfo, u16 speed);
void m4aMPlayImmInit(struct MusicPlayerInfo *mplayInfo);
void m4aMPlayStop(struct MusicPlayerInfo *mplayInfo);
void m4aMPlayVolumeControl(struct MusicPlayerInfo *mplayInfo, u16 trackBits, u16 volume);
void m4aSoundVSync(void);

extern struct MusicPlayerInfo gMPlayInfo_BGM;
extern struct MusicPlayerInfo gMPlayInfo_Fanfare;
extern struct MusicPlayerInfo gMPlayInfo_SE1;
extern struct MusicPlayerInfo gMPlayInfo_SE2;
extern struct MusicPlayerInfo gMPlayInfo_SE3;
extern struct MusicPlayerInfo gMPlayInfo_SE4;
extern struct MusicPlayerInfo gMPlayInfo_SE5;
extern struct MusicPlayerInfo gMPlayInfo_SE6;

#endif //GUARD_M4A_H
