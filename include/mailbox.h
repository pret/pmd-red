#ifndef GUARD_MAILBOX_H
#define GUARD_MAILBOX_H 

struct unkStruct_203B304
{
    // size: 0xB6 << 1
    u32 state;
    u32 unk4;
    u8 unk8;
    u8 unk9;
    u8 fillA[0xC - 0xA];
    u32 unkC;
    u8 fill10[0x50 - 0x10];
    u8 unk50;
    u8 fill51[0x64 - 0x51];
    u32 unk64;
    u32 unk68;
    u32 unk6C;
    u8 fill70[0xBC - 0x70];
    struct MenuItem unkBC[8];
    u16 unkFC[8];
    struct UnkTextStruct2 unk10C[4];
};

extern void SetMailboxState(u32);

#endif // GUARD_MAILBOX_H
