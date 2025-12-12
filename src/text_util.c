#include "global.h"
#include "globaldata.h"
#include "text_util.h"

// Not sure what the deal is with these two funcs. GetCharId is mostly used alongside GetCharacter function, which gets char info, such as width, etc.
s32 ReturnIntFromChar(u8 c)
{
    return c;
}

// arm9.bin::020614D0
u32 GetCharId(u8 c)
{
    return c;
}

UNUSED static void sub_8092290(u8 *buffer, u8 *string)
{
    while( *string != '\0' ) {
        *buffer++ = GetCharId(*string++);
    }
    *buffer = '\0'; // append terminating char
}

void StrncpyCustom(u8 *buffer, const u8 *string, s32 n)
{
    while (TRUE) {
        if (n-- <= 0 || *string == '\0') {
            break;
        }
        *buffer++ = GetCharId(*string++);
    }
    *buffer = '\0'; // append terminating char
}

// Inverted font block - maybe used in international/Japanese games?
static const u8 *const sInvertedFontDigits[] = {
    _("０"),
    _("１"),
    _("２"),
    _("３"),
    _("４"),
    _("５"),
    _("６"),
    _("７"),
    _("８"),
    _("９"),
};

UNUSED static const u8 *GetDigitInvertedFontStr(u32 digit)
{
    return sInvertedFontDigits[digit];
}

void CopyStringtoBuffer(u8 *buffer, const u8 *string)
{
    while( *string != '\0' ) {
        *buffer++ = *string++;
    }
    *buffer = '\0'; // append a terminating char
}

void BoundedCopyStringtoBuffer(u8 *buffer, u8 *string, s32 size)
{
    while( 1 ) {
        if (size-- < 1) {
            break;
        }
        if (*string == '\0') {
            *buffer = '\0'; // append a terminating char and break
            break;
        }
        // NOTE: *buffer++ = *string++ causes register flip
        *buffer = *string;
        buffer++;
        string++;
    }
}
