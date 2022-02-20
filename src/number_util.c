#include "global.h"
#include "number_util.h"


s32 RoundUpFixedPoint(s32 fixedPointNumber)
{
    if ((s16) fixedPointNumber == 0)
    {
        if (fixedPointNumber >> 16 == 0)
        {
            return 0;
        }
        return 1;
    }
    else if (fixedPointNumber >> 16 != 0)
    {
        return (s16) fixedPointNumber + 1;
    }
    else
    {
        return (s16) fixedPointNumber;
    }
}

