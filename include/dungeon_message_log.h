#ifndef GUARD_DUNGEON_MESSAGE_LOG_H
#define GUARD_DUNGEON_MESSAGE_LOG_H

// These flags are used in dungeon message log and dungeon menu recruitment file. It's possible these are general scroll flags and should be put elsewhere, like text.h, assuming more files actually use it.
#define FLAG_CAN_SCROLL_UP      0x1
#define FLAG_CAN_SCROLL_DOWN    0x2

void ResetMessageLog(void);
void CopyStringToMessageLog(const u8 *src, u32 a1, u32 a2);
bool32 DisplayMessageLog(void);

#endif
