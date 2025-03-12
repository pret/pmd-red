#ifndef GUARD_STR_STATUS_TEXT_H
#define GUARD_STR_STATUS_TEXT_H

#define MAX_STATUS_TEXTS 4

// size: 0x8
struct StatusText
{
    u8 *name;
    u8 *desc;
};

#endif // GUARD_STR_STATUS_TEXT_H
