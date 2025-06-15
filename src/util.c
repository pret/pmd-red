#include "global.h"
#include "globaldata.h"
#include "util.h"

void ReverseString(u8 *s, s32 len)
{
    u8 *l = s;
    s32 right = len - 1;
    u8 *r = s + right;
    s32 left = 0;

    while (left < right)
    {
        u8 temp = *l;
        *l++ = *r;
        *r-- = temp;
        left++;
        right--;
    }
}

// arm9.bin::0201275C
s32 ConvertToDecimal(s32 *decimal, s32 n, s32 len)
{
    s32 sign;
    s32 i;

    if (n > 0)
    {
        sign = 1;
    }
    else
    {
        n = -n;
        sign = -1;
    }

    for (i = 0; i < len; i++)
    {
        decimal[i] = n % 10;
        n /= 10;
    }

    return sign;
}

s32 ConvertFromDecimal(s32 *decimal, s32 sign, s32 len)
{
    s32 i;
    s32 powerOfTen;
    s32 n = *decimal++;

    for (i = 1, powerOfTen = 10; i < len; i++, powerOfTen *= 10)
    {
        n += *decimal++ * powerOfTen;
    }

    return (sign < 0) ? -n : n;
}

s32 ConvertFromBCD(s32 bcd)
{
    s32 powerOfTen = 1;
    s32 n = 0;

    while (bcd > 0)
    {
        n += (bcd & 0xF) * powerOfTen;
        powerOfTen *= 10;
        bcd >>= 4;
    }

    return n;
}

s32 ConvertToBCD(s32 n)
{
    s32 shift = 0;
    s32 bcd = 0;

    while (n > 0)
    {
        bcd += (n % 10) << shift;
        shift += 4;
        n /= 10;
    }

    return bcd;
}
