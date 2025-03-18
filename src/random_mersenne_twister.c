#include "global.h"
#include "globaldata.h"
#include "random_mersenne_twister.h"

// Implementation and names based on https://en.wikipedia.org/wiki/Mersenne_Twister

#define n (624) // degree of recurrence
#define m (397) // middle word, an offset used in the recurrence relation defining the series x, 1 <= m < n
#define w (32) // word size (in number of bits)
#define r (31) // separation point of one word, or the number of bits of the lower bitmask, 0 <= r <= w − 1
#define UMASK (0xffffffffU << r)
#define LMASK (0xffffffffU >> (w-r))
#define a (0x9908b0dfU) // coefficients of the rational normal form twist matrix
// additional Mersenne Twister tempering bit shifts/masks
#define u (11)
#define s (7)
#define t (15)
#define l (18)
// tempering bitmasks
#define b (0x9d2c5680U)
#define c (0xefc60000U)
#define f (1812433253U)
#define INITIAL_SEED (19650218U) // // suggested initial seed

static IWRAM_DATA u32 sStateArray[n] = {0}; // the array for the state vector
static EWRAM_INIT s32 sStateIndex = n + 1; // index into state vector array, 0 <= state_index <= n-1
static EWRAM_INIT u32 sTwistMatrix[2] = {0, a};

void MersenneTwister_InitializeState(u32 seed)
{
    sStateArray[0] = seed;

    for (sStateIndex = 1; sStateIndex < n; sStateIndex++) {
        sStateArray[sStateIndex] =
            (sStateArray[sStateIndex - 1] ^
            (sStateArray[sStateIndex - 1] >> (w - 2))) * f + sStateIndex;
    }
}

// Apparently this could improve entropy of the randomness...Though it remained unused.
UNUSED static void MersenneTwister_MixSeeds(u32 *seeds, s32 count)
{
    s32 i;
    s32 id;
    s32 seedId;

    MersenneTwister_InitializeState(INITIAL_SEED);
    id = 1;
    seedId = 0;

    for (i = max(count, n); i != 0; i--) {
        u32 bits = sStateArray[id - 1] ^ (sStateArray[id - 1] >> (w - 2));
        sStateArray[id] = (sStateArray[id] ^ (bits * 0x19660d)) + seeds[seedId] + seedId;

        id++;
        seedId++;
        if (id >= n) {
            sStateArray[0] = sStateArray[n - 1];
            id = 1;
        }
        if (seedId >= count) {
            seedId = 0;
        }
    }

    for (i = n - 1; i != 0; i--) {
        u32 bits = sStateArray[id - 1] ^ (sStateArray[id - 1] >> (w - 2));
        sStateArray[id] = (sStateArray[id] ^ (bits * 0x5d588b65)) - id;

        id++;
        if (id >= n) {
            sStateArray[0] = sStateArray[n - 1];
            id = 1;
        }
    }

    sStateArray[0] = UMASK;
}

s32 Random32MersenneTwister(void)
{
    u32 bits1, bits2;
    s32 i;

    if (sStateIndex >= n) {
        // Re-initialize state if all numbers were used
        if (sStateIndex == n + 1) {
            MersenneTwister_InitializeState(0x1571);
        }

        for (i = 0; i < 227; i++) {
            bits1 = (sStateArray[i] & UMASK) | (sStateArray[i + 1] & LMASK);
            bits2 = sStateArray[i + m] ^ (bits1 >> 1);
            sStateArray[i] = bits2 ^ sTwistMatrix[bits1 & 1];
        }
        for (; i < n - 1; i++) {
            bits1 = (sStateArray[i] & UMASK) | (sStateArray[i + 1] & LMASK);
            bits2 = sStateArray[i - 227] ^ (bits1 >> 1);
            sStateArray[i] = bits2 ^ sTwistMatrix[bits1 & 1];
        }

        bits1 = (sStateArray[n - 1] & UMASK) | (sStateArray[0] & LMASK);
        bits2 = sStateArray[m - 1] ^ (bits1 >> 1);
        sStateArray[n - 1] = bits2 ^ sTwistMatrix[bits1 & 1];
        sStateIndex = 0;
    }

    // tempering
    bits1 = sStateArray[sStateIndex++];
    bits1 ^= (bits1 >> u);
    bits1 ^= (bits1 << s) & b;
    bits1 ^= (bits1 << t) & c;
    bits1 ^= (bits1 >> l);
    return bits1;
}
