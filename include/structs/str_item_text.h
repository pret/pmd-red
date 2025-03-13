#ifndef GUARD_STR_ITEM_TEXT_H
#define GUARD_STR_ITEM_TEXT_H

// size: 0x8
typedef struct ItemText
{
    const u8 *desc;
    const u8 *useText;
} ItemText;

extern const ItemText gActions[];

#endif
