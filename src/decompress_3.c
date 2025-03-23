#include "global.h"
#include "decompress_3.h"

// TODO: Find these 2 funcs in blue.

UNUSED static bool32 IsATxPCompressed_unused(char *data)
{
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '4' && data[3] == 'P')) return TRUE;
    if ((data[0] == 'A' && data[1] == 'T' && data[2] == '3' && data[3] == 'P')) return TRUE;
    return FALSE;
}

bool8 StrsDifferent_IgnoreCase(const char *strA, const char *strB, s32 maxLen)
{
    s32 i;

    for (i = 0; i < maxLen; i++) {
        char a = strA[i];
        char b = strB[i];

        // Uppercase -> lowercase
        if ('A' <= a && a <= 'Z')
            a += 0x20;
        if ('A' <= b && b <= 'Z')
            b += 0x20;

        if (a != b)
            return TRUE;
        // `a` and `b` are equal here, but we check them for null terminators since `maxLen` is just a suggestion
        if (a == '\0' /*&& b == '\0'*/)
            break;
    }
    return FALSE;
}
