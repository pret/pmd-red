#include "global.h"
#include "code_8012A18_1.h"
#include "sprite_oam.h"
#include "text_util.h"
#include "text2.h"

struct unkStruct_203B1FC
{
    // size: 0x198
    u32 unk0;
    u8 unk4;
    SpriteOAM unk6;
    SpriteOAM unkE;
    u8 unk16;
    u8 unk17;
    u8 unk18;
    u8 unk1B;
    u8 unk1C;
    s16 unk1E[1];
    u8 fill20[0x8A - 0x20];
    s16 unk8A[2];
    u8 fill8E[0xF8 - 0x8E];
    u8 *unkF8;
    u8 unkFC[54];
};

extern struct unkStruct_203B1FC *gUnknown_203B1FC;

s32 sub_8015F44(void)
{
    s32 index;
    s32 counter;
    index = 0;

    if (index < gUnknown_203B1FC->unk1B && gUnknown_203B1FC->unkF8[0] != 0) {
        index = 1;
        counter = 1;
        while (TRUE) {
            if (counter >= gUnknown_203B1FC->unk1B)
                return index;
            if (gUnknown_203B1FC->unkF8[counter] == 0)
                return index;
            index = counter + 1;
            counter = index;
        }
    }
    return index;
}

void sub_8015F84(void)
{
    u32 uVar2;
    const struct unkChar *puVar3;
    s32 index;
    s32 total;

    total = 0;
    for(index = 0; index < gUnknown_203B1FC->unk1B; index++)
    {
        gUnknown_203B1FC->unk1E[index] = total;
        if (gUnknown_203B1FC->unkF8[index] == 0) {
            gUnknown_203B1FC->unk8A[index] = 8;
            return;
        }
        uVar2 = ReturnIntFromChar2(gUnknown_203B1FC->unkF8[index]);
        puVar3 = GetCharacter(uVar2);
        gUnknown_203B1FC->unk8A[index] = puVar3->unk6;
        total += puVar3->unk6;
    }
}

// TODO: Above code is in code_80130A8.s

s32 sub_8015FEC(u8 *buffer, s32 size)
{
    const struct unkChar *iVar2;
    s32 currLength;
    s32 length;
    u8 *bufferPtr;

    length = 0;
    currLength = 0;

    if (currLength < size && *buffer != '\0') {
        bufferPtr = buffer; // Had to have another variable to match..
        do {
            iVar2 = GetCharacter(ReturnIntFromChar2(*bufferPtr));
            length += iVar2->unk6;
            bufferPtr++;
            currLength++;
        } while (currLength < size && *bufferPtr != '\0');
    }

    return length;
}

s32 sub_8016028(void)
{
    return 60;
}
