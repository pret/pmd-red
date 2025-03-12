#ifndef GUARD_STR_STATUS_TEXT_H
#define GUARD_STR_STATUS_TEXT_H

#define MAX_STATUS_TEXTS 4

// size: 0x8
typedef struct StatusText
{
    u8 *name;
    u8 *desc;
} StatusText;

// size: 0x20
#define STATUSTEXTS(name) const StatusText *(name) [MAX_STATUS_TEXTS]

#endif // GUARD_STR_STATUS_TEXT_H