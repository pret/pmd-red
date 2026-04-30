#ifndef GUARD_CODE_800558C_H
#define GUARD_CODE_800558C_H

extern bool8 gDrawWindow;
extern s16 *gWinBufferPtr;
extern s16 gUnknown_2026E4E;

extern s16 *gWindowBgCopy;

typedef enum CopyWindowBgBufferType {
    COPY_WINDOW_BG_BUFFER_DEFAULT,
    COPY_WINDOW_BG_BUFFER_DIM2,     // Dim while in light darkness corridor
    COPY_WINDOW_BG_BUFFER_DIM1,     // Same but for heavy darkness
    COPY_WINDOW_BG_BUFFER_ROOM_DIM, // While in a room, dim outside
    COPY_WINDOW_BG_BUFFER_UNK4,
    COPY_WINDOW_BG_BUFFER_UNK5,
} CopyWindowBgBufferType;

void WindowBgBufferInit(void);
void CopyWindowBgBuffer(s32 *pos, u8 kind);
void ToggleWindowBgBuffer(void);

#endif // GUARD_CODE_800558C_H
