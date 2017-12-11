#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include "gba/gba.h"

// IDE support
#ifdef __APPLE__
#define _(x) x
#define __(x) x
#define INCBIN_U8 {0}
#define INCBIN_U16 {0}
#define INCBIN_U32 {0}
#define INCBIN_S8 {0}
#define INCBIN_S16 {0}
#define INCBIN_S32 {0}
void *     memcpy (void *, const void *, size_t);
void *     memset (void *, int, size_t);
int     strcmp (const char *, const char *);
#endif

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided\n")

#define nonmatching(fndec, x) {\
__attribute__((naked))\
fndec\
{\
    asm_unified(x);\
}\
}

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#endif // GUARD_GLOBAL_H
