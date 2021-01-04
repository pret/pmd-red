struct BGControlStruct
{
    u16 padding;
    u16 unk2;
    s16 hofs;
    s16 vofs;
};

void SetBG0RegOffsets(s32 xoffset, s32 yoffset);
void SetBG1RegOffsets(s32 xoffset, s32 yoffset);
void SetBG2RegOffsets(s32 xoffset, s32 yoffset);
void SetBG3RegOffsets(s32 xoffset, s32 yoffset);
void SetBGRegOffsets(s32 reg, u32 xoffset, s32 yoffset);
void SetBGRegXOffset(s32 reg, s32 offset);
void SetBGRegYOffset(s32 reg, s32 offset);
void UpdateBGControlRegisters(void);
void SetBGOBJEnableFlags(u32 mask);

