#ifndef GUARD_CONSTANTS_DIRECTION_H
#define GUARD_CONSTANTS_DIRECTION_H

#define DIRECTION_MASK 7
#define DIRECTION_MASK_CARDINAL 6 // Only South, East, North and West

enum Direction
{
    DIRECTION_SOUTH,
    DIRECTION_SOUTHEAST,
    DIRECTION_EAST,
    DIRECTION_NORTHEAST,
    DIRECTION_NORTH,
    DIRECTION_NORTHWEST,
    DIRECTION_WEST,
    DIRECTION_SOUTHWEST,

    NUM_DIRECTIONS
};

enum DirectionTransformation
{
    DIR_TRANS_NONE,
    DIR_TRANS_SPINRIGHT1, // Spin right 1 (example: South -> SouthWest)
    DIR_TRANS_SPINLEFT1, // Spin left 1 (example: South -> SouthEast)
    DIR_TRANS_SPINRIGHT2, // Spin right 2 (example: South -> West)
    DIR_TRANS_SPINLEFT2, // Spin left 2 (example: South -> East)
    DIR_TRANS_FLIP, // Flip (example: South -> North)
    DIR_TRANS_RAND_OFFSET_SOFT_CARDINAL, // Like DIR_TRANS_RAND_OFFSET_SOFT but only results in cardinal directions
    DIR_TRANS_RAND_OFFSET_SOFT, // SpinLeft1 or Nothing or SpinRight1
    DIR_TRANS_RAND_CARDINAL, // Random non-diagonal
    DIR_TRANS_RAND, // Fully random
    DIR_TRANS_10,
    DIR_TRANS_11,
};

#endif // GUARD_CONSTANTS_DIRECTION_H
