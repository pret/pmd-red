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

extern struct MusicPlayerInfo gUnknown_20008F0; // BGM??


#endif //GUARD_M4A_H
