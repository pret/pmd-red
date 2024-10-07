#include "global.h"
#include "code_8012A18_1.h"
#include "text_util.h"
#include "text2.h"

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
