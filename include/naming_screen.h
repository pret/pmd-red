#ifndef GUARD_NAMING_SCREEN_H
#define GUARD_NAMING_SCREEN_H

u32 NamingScreen_Init(u32 type, u8 *defaultText);
u32 NamingScreen_HandleInput(void);
void NamingScreen_Free(void);
s32 GetStrWidth(const u8 *buffer, s32 size);
s32 GetMaxPokeNameWidth(void);

#endif
