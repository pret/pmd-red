#ifndef GUARD_STR_STAT_INDEX_X
#define GUARD_STR_STAT_INDEX_X

#define STAT_INDEX_PHYSICAL 0 // Atk, Def
#define STAT_INDEX_SPECIAL 1 // Sp Atk, Sp Def
#define STAT_INDEX_ACCURACY STAT_INDEX_PHYSICAL
#define STAT_INDEX_EVASION STAT_INDEX_SPECIAL

// Needed to match in Blue/Sky. I wonder what was the reason for making it a struct as opposed to a simple int...
typedef struct StatIndex
{
    s32 id;
} StatIndex;

#endif // GUARD_STR_STAT_INDEX_X
