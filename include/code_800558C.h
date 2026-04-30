#ifndef GUARD_CODE_800558C_H
#define GUARD_CODE_800558C_H

extern bool8 gDrawWindow;
extern s16 *gWin0HPtr;
extern s16 gUnknown_2026E4E;

extern s16 *gWindowBgCopy;

typedef enum CopyWindowBgBufferType {
    COPY_WINDOW_BG_BUFFER_DEFAULT,
    COPY_WINDOW_BG_BUFFER_DIM2,
    COPY_WINDOW_BG_BUFFER_DIM1,
    COPY_WINDOW_BG_BUFFER_UNK3,
    COPY_WINDOW_BG_BUFFER_UNK4,
    COPY_WINDOW_BG_BUFFER_UNK5,
} CopyWindowBgBufferType;

void WindowBgBufferInit(void);
void CopyWindowBgBuffer(s32 *a0, u8 kind);
void ToggleWindowBgBuffer(void);

#endif // GUARD_CODE_800558C_H
