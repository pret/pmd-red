#ifndef GUARD_GLOBAL_H
#define GUARD_GLOBAL_H

#include <stdarg.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>
#include <stdlib.h>
#include "config.h" // We need to define config before gba headers as print stuff needs the functions nulled before defines.
#include "gba/gba.h"

#include "constants/global.h"
#include "constants/monster.h"

#define VERSION_BLUE 0
#define VERSION_RED 1
#define GAME_VERSION VERSION_RED

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

// Needed to match a couple of functions.
static inline u8 *InlineStrcpy(u8 *dst, const u8 *src)
{
    return strcpy(dst, src);
}

static inline u8 *InlineStrncpy(u8 *dst, const u8 *src, s32 n)
{
    return strncpy(dst, src, n);
}

static inline u8 *InlineStrcat(u8 *dst, u8 *src)
{
    return strcat(dst, src);
}

static inline bool8 AreStringsDifferent(const u8 *str1, const u8 *str2)
{
    return strcmp(str1, str2) != 0;
}

#ifdef MODERN
#define BUGFIX
#define NONMATCHING

#include "mini_printf.h"
void sprintfStatic(char *buffer, const char *text, ...);
// Use miniprintf instead of library printf functions
#define sprintf sprintfStatic
#define vsprintf mini_vsprintf
#endif // MODERN

// Sometimes incrementing and decrementing a variable changes how registers are allocated, which helps with matching functions. Functionality-wise this doesn't do anything.
#ifdef NONMATCHING
#define ASM_MATCH_TRICK(a) {;}
#else
#define ASM_MATCH_TRICK(a) {a++;a--;}
#endif // NONMATCHING

#ifdef NONMATCHING
#define CMP_S8_NOT_MINUS1(val)(val != -1)
#else
#define CMP_S8_NOT_MINUS1(val)((val << 0x18) != ((s8)(-1) << 0x18))
#endif

// to help in decompiling
#define asm_comment(x) asm volatile("@ -- " x " -- ")

#define asm_unified(x) asm(".syntax unified\n" x "\n.syntax divided\n")

#define ARRAY_COUNT(array) (sizeof(array) / sizeof((array)[0]))
#define ARRAY_COUNT_INT(array) ((s32)(ARRAY_COUNT(array))) // When an int is needed to match.

#define SWAP(a, b, temp)    \
{                           \
    temp = a;               \
    a = b;                  \
    b = temp;               \
}

#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#endif // GUARD_GLOBAL_H
