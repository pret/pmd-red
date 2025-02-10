#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <string.h>
#include "config.h" // We need to define config before gba headers as print stuff needs the functions nulled before defines.
#include "gba/gba.h"

#include "constants/global.h"
#include "constants/monster.h"

// IDE support
#if defined(__APPLE__) || defined(__CYGWIN__)
#define _(x) x
#define __(x) x
#define INCBIN(...) {0}
#define INCBIN_U8   INCBIN
#define INCBIN_U16  INCBIN
#define INCBIN_U32  INCBIN
#define INCBIN_S8   INCBIN
#define INCBIN_S16  INCBIN
#define INCBIN_S32  INCBIN
#define INCBIN_COMP INCBIN
#endif

// Prevent cross-jump optimization.
#define BLOCK_CROSS_JUMP asm("");

// s16 cause reg alloc problems in almost all functions where they're passed as arguments. This static inline sometimes helps with generating good asm.
static inline s16 Self_s16(s16 a)
{
    return a;
}

// Sometimes incrementing and decrementing a variable changes how registers are allocated, which helps with matching functions. Functionality-wise this doesn't do anything.
#ifdef NONMATCHING
#define ASM_MATCH_TRICK(a) {;}
#else
#define ASM_MATCH_TRICK(a) {a++;a--;}
#endif // NONMATCHING

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided\n")

#define NAKED __attribute__((naked))

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#endif // GUARD_GLOBAL_H
