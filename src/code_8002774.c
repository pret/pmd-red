#include "global.h"
#include "code_8002774.h"
#include "constants/direction.h"

s32 sub_8002A70(s32 _direction1, s32 _direction2, s32 _caseId)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);
    s32 caseId = (u8)(_caseId);

    if (direction1 == direction2)
        return direction1;

    switch (caseId) {
        case 1:
            if (direction1 >= 0) {
                direction1 += 7;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 2:
            if (direction1 >= 0) {
                direction1 += 1;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 3:
            if (direction1 >= 0) {
                direction1 += 6;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 4:
            if (direction1 >= 0) {
                direction1 += 2;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case 11:
            direction1 = sub_8002B04(direction1, direction2);
            // Fallthrough
        case 10:
            direction1 = sub_8002B04(direction1, direction2);
            break;
    }
    return direction1;
}

s32 sub_8002B04(s32 _direction1, s32 _direction2)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);

    if (direction2 != -1)
    {
        s32 newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != 0) {
            if (newDirection < 4)
                newDirection = (direction1 + 1) % NUM_DIRECTIONS;
            else
                newDirection = (direction1 + 7) % NUM_DIRECTIONS;

            direction1 = (s8)newDirection;
        }
    }
    return direction1;
}
