#include "global.h"
#include "decompress_sir.h"
#include "structs/axdata.h"
const struct EfoFileData gUnknown_97EC8C4;
const SiroArchive gUnknown_97EB458 = { "SIRO", &gUnknown_97EC8C4 };
const ax_pose gUnknown_97EB468[] = {
    { -1, { 0, 127 }, 479, 45312, 39936 },
    { -1, { 0, 127 }, 16895, 45312, 39952 },
    { -1, { 0, 127 }, 479, 41184, 39936 },
    { -1, { 0, 127 }, 16895, 41184, 39952 },
    { -1, { 0, 127 }, 16911, 24800, 39960 },
    { -1, { 0, 127 }, 535, 12544, 39964 },
    { -1, { 0, 127 }, 16911, 28928, 39960 },
    { -1, { 0, 127 }, 535, 8440, 39964 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB4C2[] = {
    { -1, { 0, 127 }, 506, 45307, 39965 },
    { -1, { 0, 127 }, 506, 45275, 39981 },
    { -1, { 0, 127 }, 474, 45307, 39997 },
    { -1, { 0, 127 }, 474, 45275, 40013 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB4F4[] = {
    { -1, { 0, 0 }, 480, 37120, 40029 },
    { -1, { 0, 0 }, 480, 37088, 40045 },
    { -1, { 0, 0 }, 512, 45312, 40029 },
    { -1, { 0, 0 }, 512, 45280, 40045 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB526[] = {
    { -1, { 0, 0 }, 485, 37116, 39965 },
    { -1, { 0, 0 }, 485, 37084, 39981 },
    { -1, { 0, 0 }, 517, 37116, 39997 },
    { -1, { 0, 0 }, 517, 37084, 40013 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB558[] = {
    { -1, { 0, 0 }, 513, 37120, 39936 },
    { -1, { 0, 0 }, 16881, 37120, 39952 },
    { -1, { 0, 0 }, 513, 32992, 39936 },
    { -1, { 0, 0 }, 16881, 32992, 39952 },
    { -1, { 0, 0 }, 16873, 16608, 39960 },
    { -1, { 0, 0 }, 481, 4352, 39964 },
    { -1, { 0, 0 }, 16873, 20736, 39960 },
    { -1, { 0, 0 }, 481, 248, 39964 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB5B2[] = {
    { -1, { 0, 0 }, 485, 32997, 39965 },
    { -1, { 0, 0 }, 485, 33029, 39981 },
    { -1, { 0, 0 }, 517, 32997, 39997 },
    { -1, { 0, 0 }, 517, 33029, 40013 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB5E4[] = {
    { -1, { 0, 0 }, 480, 32992, 40029 },
    { -1, { 0, 0 }, 480, 33024, 40045 },
    { -1, { 0, 0 }, 512, 41184, 40029 },
    { -1, { 0, 0 }, 512, 41216, 40045 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB616[] = {
    { -1, { 0, 127 }, 506, 41189, 39965 },
    { -1, { 0, 127 }, 506, 41221, 39981 },
    { -1, { 0, 127 }, 474, 41189, 39997 },
    { -1, { 0, 127 }, 474, 41221, 40013 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
const ax_pose gUnknown_97EB648[] = {
    { -1, { 0, 0 }, 508, 252, 40061 },
    { -1, { 255, -1 }, 65535, 65535, 65535 },
};
UNUSED const u32 gUnknown_97EB65C = 126;
const ax_anim gUnknown_97EB660[] = {
    { 1,   0,   0, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB684[] = {
    { 1,   0,   1, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB6A8[] = {
    { 1,   0,   2, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB6CC[] = {
    { 1,   0,   3, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB6F0[] = {
    { 1,   0,   4, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB714[] = {
    { 1,   0,   5, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB738[] = {
    { 1,   0,   6, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const ax_anim gUnknown_97EB75C[] = {
    { 1,   0,   7, { 0, 0 }, { 0, 0 } },
    { 1,   0,   8, { 0, 0 }, { 0, 0 } },
    { 0,   0,   0, { 0, 0 }, { 0, 0 } },
};
const u32 gUnknown_97EB780[] = INCBIN_U32("data/effects/efob045.4bpp");
const RGB gUnknown_97EC740[] = INCBIN_U8("data/effects/efob045.pmdpal");
const ax_pose *const gUnknown_97EC780[] = {
    gUnknown_97EB468,
    gUnknown_97EB4C2,
    gUnknown_97EB4F4,
    gUnknown_97EB526,
    gUnknown_97EB558,
    gUnknown_97EB5B2,
    gUnknown_97EB5E4,
    gUnknown_97EB616,
    gUnknown_97EB648,
};
const ax_anim *const gUnknown_97EC7A4[] = {
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
    gUnknown_97EB660,
};
const ax_anim *const gUnknown_97EC7C4[] = {
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
    gUnknown_97EB684,
};
const ax_anim *const gUnknown_97EC7E4[] = {
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
    gUnknown_97EB6A8,
};
const ax_anim *const gUnknown_97EC804[] = {
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
    gUnknown_97EB6CC,
};
const ax_anim *const gUnknown_97EC824[] = {
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
    gUnknown_97EB6F0,
};
const ax_anim *const gUnknown_97EC844[] = {
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
    gUnknown_97EB714,
};
const ax_anim *const gUnknown_97EC864[] = {
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
    gUnknown_97EB738,
};
const ax_anim *const gUnknown_97EC884[] = {
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
    gUnknown_97EB75C,
};
const ax_anim *const *const gUnknown_97EC8A4[] = {
    gUnknown_97EC7A4,
    gUnknown_97EC7C4,
    gUnknown_97EC7E4,
    gUnknown_97EC804,
    gUnknown_97EC824,
    gUnknown_97EC844,
    gUnknown_97EC864,
    gUnknown_97EC884,
};
const EfoFileData gUnknown_97EC8C4 = {
    gUnknown_97EC780,
    gUnknown_97EC8A4,
    ARRAY_COUNT(gUnknown_97EC8A4), // 8
    NULL,
    NULL,
    gUnknown_97EB780,
    gUnknown_97EC740,
    sizeof(gUnknown_97EB780) / 32, // 126
};
