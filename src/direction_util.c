#include "global.h"
#include "globaldata.h"
#include "direction_util.h"
#include "constants/direction.h"
#include "structs/str_position.h"
#include "other_random.h"

UNUSED static const u8 sUnusedZeroArray[] = {0, 0, 0, 0, 0, 0, 0, 0};

static const PixelPos sVectorDirections[NUM_DIRECTIONS] = {
    {0, 1}, // N
    {1, 1}, // NE
    {1, 0}, // E
    {1, -1}, // SE
    {0, -1}, // S
    {-1, -1}, // SW
    {-1, 0}, // W
    {-1, 1}, // NW
};


static s8 VecDirection4Radial(PixelPos *pixelPos);

static inline s8 GetRandomizedDirection(s32 dir, s32 randExclusiveMax, s32 add, s32 multi)
{
    return (s8)(((dir + add) + (OtherRandInt(randExclusiveMax) * multi)) % NUM_DIRECTIONS);
}

// arm9.bin::020109F4
s32 TransformDirection1(s32 _direction1, u32 caseID)
{
    s32 dir = (s8) _direction1;
    switch((u8)caseID) {
        case DIR_TRANS_SPINRIGHT1:
            if (dir >= 0) {
                dir += 7;
                dir &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINLEFT1:
            if (dir >= 0) {
                dir += 1;
                dir &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINRIGHT2:
            if (dir >= 0) {
                dir += 6;
                dir &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINLEFT2:
            if (dir >= 0) {
                dir += 2;
                dir &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_FLIP:
            if (dir >= 0) {
                dir += 4;
                dir &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_RAND_OFFSET_SOFT_CARDINAL:
            if ((dir & 1) != 0) {
                // Diagonal
                dir = GetRandomizedDirection(dir, 2, 7, 2); // spinRight1 + (0 or spinLeft2)
            }
            else {
                // Cardinal
                dir = GetRandomizedDirection(dir, 3, 6, 2); // spinRight2 + (0 or spinLeft2 or flip)
            }
            break;
        case DIR_TRANS_RAND_OFFSET_SOFT:
            dir = GetRandomizedDirection(dir, 3, 7, 1); // spinRight1 + (0 or spinLeft1 or spinLeft2)
            break;
        case DIR_TRANS_RAND_CARDINAL:
            dir = (s8)(OtherRandInt(NUM_DIRECTIONS) & (u8)~1);
            break;
        case DIR_TRANS_RAND:
            dir = (s8) OtherRandInt(NUM_DIRECTIONS);
            break;
        default:
            break;
    }
    return dir;
}

// arm9.bin::020108EC
s32 TransformDirection2(s32 _direction1, s32 _direction2, s32 _caseId)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);
    s32 caseId = (u8)(_caseId);

    if (direction1 == direction2)
        return direction1;

    switch (caseId) {
        case DIR_TRANS_SPINRIGHT1:
            if (direction1 >= 0) {
                direction1 += 7;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINLEFT1:
            if (direction1 >= 0) {
                direction1 += 1;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINRIGHT2:
            if (direction1 >= 0) {
                direction1 += 6;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_SPINLEFT2:
            if (direction1 >= 0) {
                direction1 += 2;
                direction1 &= DIRECTION_MASK;
            }
            break;
        case DIR_TRANS_11:
            direction1 = sub_8002B04(direction1, direction2);
            // Fallthrough
        case DIR_TRANS_10:
            direction1 = sub_8002B04(direction1, direction2);
            break;
    }
    return direction1;
}

// arm9.bin::02010824
s32 sub_8002B04(s32 _direction1, s32 _direction2)
{
    s32 direction1 = (s8)(_direction1);
    s32 direction2 = (s8)(_direction2);

    if (direction2 != -1)
    {
        s32 newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != DIRECTION_SOUTH) {
            if (newDirection <= DIRECTION_NORTHEAST)
                newDirection = (direction1 + 1) % NUM_DIRECTIONS; // Spin Left 1
            else
                newDirection = (direction1 + 7) % NUM_DIRECTIONS; // Spin Right 1

            direction1 = (s8)newDirection;
        }
    }
    return direction1;
}

#if (GAME_VERSION == VERSION_RED)
UNUSED static s32 sub_8002B5C(s32 _direction1, s32 _direction2)
{
    s32 newDirection;
    s32 direction1;
    s32 direction2;

    direction1 = (s8)_direction1;
    direction2 = (s8)_direction2;

    if (direction2 != -1) {
        newDirection = ((direction2 + NUM_DIRECTIONS) - direction1) % NUM_DIRECTIONS;

        if (newDirection != DIRECTION_SOUTH) {
            if (newDirection <= DIRECTION_NORTHEAST) {
                newDirection = (direction1 + 2) % NUM_DIRECTIONS; // Spin Left 2
            }
            else {
                newDirection = (direction1 + 6) % NUM_DIRECTIONS; // Spin Right 2
            }
            direction1 = (s8)(newDirection);
        }
    }
    return direction1 & DIRECTION_MASK_CARDINAL;
}
#endif

// arm9.bin::02010790
PixelPos SetVecFromDirectionSpeed(s32 _dir, u32 speed)
{
    s32 dir = (s8) _dir;
    const PixelPos *vec = &sVectorDirections[dir];

    return (PixelPos){ .x = vec->x * speed, .y = vec->y * speed };
}

UNUSED static s32 VecDirection8Sign(PixelPos *param_1)
{
    if (param_1->x < 0) {
        if (param_1->y < 0)
            return DIRECTION_NORTHWEST;
        else if (param_1->y > 0)
            return DIRECTION_SOUTHWEST;
        else
            return DIRECTION_WEST;
    }
    else if (param_1->x > 0) {
        if (param_1->y < 0)
            return DIRECTION_NORTHEAST;
        else if (param_1->y > 0)
            return DIRECTION_SOUTHEAST;
        else
            return DIRECTION_EAST;
    }
    else if (param_1->y < 0)
        return DIRECTION_NORTH;
    else if (param_1->y > 0)
        return DIRECTION_SOUTH;
    else
        return -1;
}

UNUSED static s32 VecDirection4SignYX(PixelPos *param_1)
{
    if (param_1->y < 0) {
        return DIRECTION_NORTH;
    }
    else if (param_1->y > 0) {
        return DIRECTION_SOUTH;
    }
    else  if (param_1->x < 0) {
        return DIRECTION_WEST;
    }
    else if (param_1->x > 0) {
        return DIRECTION_EAST;
    }
    else {
        return -1;
    }
}

// arm9.bin::02010680
s32 VecDirection8Radial(PixelPos *pixelPos)
{
    PixelPos absPos = {abs(pixelPos->x), abs(pixelPos->y)};

    if (pixelPos->x < 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_NORTH;
            }
            if (absPos.x <= absPos.y * 2) {
                return DIRECTION_NORTHWEST;
            }
            return DIRECTION_WEST;
        }
        if (absPos.y <= absPos.x * 2) {
            if (absPos.x > absPos.y * 2) {
                return DIRECTION_WEST;
            }
            return DIRECTION_SOUTHWEST;
        }
    }
    else if (pixelPos->x > 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_NORTH;
            }
            if (absPos.x <= absPos.y * 2) {
                return DIRECTION_NORTHEAST;
            }
            return DIRECTION_EAST;
        }
        else {
            if (absPos.y > absPos.x * 2) {
                return DIRECTION_SOUTH;
            }
            if (absPos.x > absPos.y * 2) {
                return DIRECTION_EAST;
            }
            return DIRECTION_SOUTHEAST;
        }
    }
    else {
        if (pixelPos->y < 0) {
            return DIRECTION_NORTH;
        }
        if (pixelPos->y < 1) {
            return -1;
        }
    }
    return DIRECTION_SOUTH;
}

// arm9.bin::020105A0
static s8 VecDirection4Radial(PixelPos *pixelPos)
{
    PixelPos absPos = {abs(pixelPos->x), abs(pixelPos->y)};

    if (pixelPos->x < 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x) {
                return DIRECTION_NORTH;
            }
            return DIRECTION_WEST;
        }
        if (absPos.y <= absPos.x) {
            return DIRECTION_WEST;
        }
    }
    else if (pixelPos->x > 0) {
        if (pixelPos->y < 0) {
            if (absPos.y > absPos.x) {
                return DIRECTION_NORTH;
            }
            return DIRECTION_EAST;
        }
        else {
            if (absPos.y > absPos.x) {
                return DIRECTION_SOUTH;
            }
            return DIRECTION_EAST;
        }
    }
    else {
        if (pixelPos->y < 0) {
            return DIRECTION_NORTH;
        }
        if (pixelPos->y < 1) {
            return -1;
        }
    }
    return DIRECTION_SOUTH;
}

// arm9.bin::02010478
s8 SizedDeltaDirection4(const PixelPos *p1, const PixelPos *p2, const PixelPos *p3, const PixelPos *p4)
{
    PixelPos newPos;

    newPos.x = p3->x - p1->x;
    newPos.y = p3->y - p1->y;

    if (newPos.x >= 0) {
        s32 x = (newPos.x + 1);
        x -= ((p2->x + p4->x) / 2);
        newPos.x = x;
        if (newPos.x < 0)
            newPos.x = 0;
    }
    else {
        s32 x = (newPos.x - 1);
        x += ((p2->x + p4->x) / 2);
        newPos.x = x;
        if (newPos.x > 0)
            newPos.x = 0;
    }

    if (newPos.y >= 0) {
        s32 y = (newPos.y + 1);
        y -= ((p2->y + p4->y) / 2);
        newPos.y = y;
        if (newPos.y < 0)
            newPos.y = 0;
    }
    else {
        s32 y = (newPos.y - 1);
        y += ((p2->y + p4->y) / 2);
        newPos.y = y;
        if (newPos.y > 0)
            newPos.y = 0;
    }

    return VecDirection4Radial(&newPos);
}

// arm9.bin::02010350
s8 SizedDeltaDirection8(const PixelPos *p1, const PixelPos *p2, const PixelPos *p3, const PixelPos *p4)
{
    PixelPos newPos;

    newPos.x = p3->x - p1->x;
    newPos.y = p3->y - p1->y;

    if (newPos.x >= 0) {
        s32 x = newPos.x + 1;
        x -= (p2->x + p4->x) / 2;
        newPos.x = x;
        if (newPos.x < 0)
            newPos.x = 0;
    }
    else {
        s32 x = newPos.x - 1;
        x += (p2->x + p4->x) / 2;
        newPos.x = x;
        if (newPos.x > 0)
            newPos.x = 0;
    }

    if (newPos.y >= 0) {
        s32 y = newPos.y + 1;
        y -= (p2->y + p4->y) / 2;
        newPos.y = y;
        if (newPos.y < 0)
            newPos.y = 0;
    }
    else {
        s32 y = newPos.y - 1;
        y += (p2->y + p4->y) / 2;
        newPos.y = y;
        if (newPos.y > 0)
            newPos.y = 0;
    }

    return (s8) VecDirection8Radial(&newPos);
}
