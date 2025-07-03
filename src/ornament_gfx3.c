#include "global.h"
#include "globaldata.h"
#include "ornament_gfx.h"

const RGB gFlag106Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag106.pmdpal") };

static const axmain sAxMainFlag106;
const SiroArchive gAxFlag106 = {"SIRO", &sAxMainFlag106};

static const ax_pose sFlag106Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag106Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag106Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag106Gfx1[] = INCBIN_U8("graphics/ornament/Flag106/sprite_1.4bpp");
static const ax_sprite sFlag106Sprites1[] = {
	{sFlag106Gfx1, ARRAY_COUNT(sFlag106Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx2[] = INCBIN_U8("graphics/ornament/Flag106/sprite_2.4bpp");
static const ax_sprite sFlag106Sprites2[] = {
	{sFlag106Gfx2, ARRAY_COUNT(sFlag106Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx3[] = INCBIN_U8("graphics/ornament/Flag106/sprite_3.4bpp");
static const ax_sprite sFlag106Sprites3[] = {
	{sFlag106Gfx3, ARRAY_COUNT(sFlag106Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx4[] = INCBIN_U8("graphics/ornament/Flag106/sprite_4.4bpp");
static const ax_sprite sFlag106Sprites4[] = {
	{sFlag106Gfx4, ARRAY_COUNT(sFlag106Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx5[] = INCBIN_U8("graphics/ornament/Flag106/sprite_5.4bpp");
static const ax_sprite sFlag106Sprites5[] = {
	{sFlag106Gfx5, ARRAY_COUNT(sFlag106Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag106Gfx6[] = INCBIN_U8("graphics/ornament/Flag106/sprite_6.4bpp");
static const ax_sprite sFlag106Sprites6[] = {
	{sFlag106Gfx6, ARRAY_COUNT(sFlag106Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag106[] = {
	sFlag106Pose1,
	sFlag106Pose2,
	sFlag106Pose3,
	sFlag106Pose4,
	sFlag106Pose5,
	sFlag106Pose6,
};

static const ax_anim *const sFlag106AnimTable1[] = {
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
	sFlag106Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag106[] = {
	sFlag106AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag106[] = {
	sFlag106Sprites1,
	sFlag106Sprites2,
	sFlag106Sprites3,
	sFlag106Sprites4,
	sFlag106Sprites5,
	sFlag106Sprites6,
};

static const axmain sAxMainFlag106 = {
	.poses = sAxPosesFlag106,
	.animations = sAxAnimationsFlag106,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag106),
	.spriteData = sAxSpritesFlag106,
	.positions = NULL,
};
const RGB gFlag107Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag107.pmdpal") };

static const axmain sAxMainFlag107;
const SiroArchive gAxFlag107 = {"SIRO", &sAxMainFlag107};

static const ax_pose sFlag107Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag107Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag107Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag107Gfx1[] = INCBIN_U8("graphics/ornament/Flag107/sprite_1.4bpp");
static const ax_sprite sFlag107Sprites1[] = {
	{sFlag107Gfx1, ARRAY_COUNT(sFlag107Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx2[] = INCBIN_U8("graphics/ornament/Flag107/sprite_2.4bpp");
static const ax_sprite sFlag107Sprites2[] = {
	{sFlag107Gfx2, ARRAY_COUNT(sFlag107Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx3[] = INCBIN_U8("graphics/ornament/Flag107/sprite_3.4bpp");
static const ax_sprite sFlag107Sprites3[] = {
	{sFlag107Gfx3, ARRAY_COUNT(sFlag107Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx4[] = INCBIN_U8("graphics/ornament/Flag107/sprite_4.4bpp");
static const ax_sprite sFlag107Sprites4[] = {
	{sFlag107Gfx4, ARRAY_COUNT(sFlag107Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx5[] = INCBIN_U8("graphics/ornament/Flag107/sprite_5.4bpp");
static const ax_sprite sFlag107Sprites5[] = {
	{sFlag107Gfx5, ARRAY_COUNT(sFlag107Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag107Gfx6[] = INCBIN_U8("graphics/ornament/Flag107/sprite_6.4bpp");
static const ax_sprite sFlag107Sprites6[] = {
	{sFlag107Gfx6, ARRAY_COUNT(sFlag107Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag107[] = {
	sFlag107Pose1,
	sFlag107Pose2,
	sFlag107Pose3,
	sFlag107Pose4,
	sFlag107Pose5,
	sFlag107Pose6,
};

static const ax_anim *const sFlag107AnimTable1[] = {
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
	sFlag107Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag107[] = {
	sFlag107AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag107[] = {
	sFlag107Sprites1,
	sFlag107Sprites2,
	sFlag107Sprites3,
	sFlag107Sprites4,
	sFlag107Sprites5,
	sFlag107Sprites6,
};

static const axmain sAxMainFlag107 = {
	.poses = sAxPosesFlag107,
	.animations = sAxAnimationsFlag107,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag107),
	.spriteData = sAxSpritesFlag107,
	.positions = NULL,
};
const RGB gFlag108Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag108.pmdpal") };

static const axmain sAxMainFlag108;
const SiroArchive gAxFlag108 = {"SIRO", &sAxMainFlag108};

static const ax_pose sFlag108Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag108Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag108Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag108Gfx1[] = INCBIN_U8("graphics/ornament/Flag108/sprite_1.4bpp");
static const ax_sprite sFlag108Sprites1[] = {
	{sFlag108Gfx1, ARRAY_COUNT(sFlag108Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx2[] = INCBIN_U8("graphics/ornament/Flag108/sprite_2.4bpp");
static const ax_sprite sFlag108Sprites2[] = {
	{sFlag108Gfx2, ARRAY_COUNT(sFlag108Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx3[] = INCBIN_U8("graphics/ornament/Flag108/sprite_3.4bpp");
static const ax_sprite sFlag108Sprites3[] = {
	{sFlag108Gfx3, ARRAY_COUNT(sFlag108Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx4[] = INCBIN_U8("graphics/ornament/Flag108/sprite_4.4bpp");
static const ax_sprite sFlag108Sprites4[] = {
	{sFlag108Gfx4, ARRAY_COUNT(sFlag108Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx5[] = INCBIN_U8("graphics/ornament/Flag108/sprite_5.4bpp");
static const ax_sprite sFlag108Sprites5[] = {
	{sFlag108Gfx5, ARRAY_COUNT(sFlag108Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag108Gfx6[] = INCBIN_U8("graphics/ornament/Flag108/sprite_6.4bpp");
static const ax_sprite sFlag108Sprites6[] = {
	{sFlag108Gfx6, ARRAY_COUNT(sFlag108Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag108[] = {
	sFlag108Pose1,
	sFlag108Pose2,
	sFlag108Pose3,
	sFlag108Pose4,
	sFlag108Pose5,
	sFlag108Pose6,
};

static const ax_anim *const sFlag108AnimTable1[] = {
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
	sFlag108Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag108[] = {
	sFlag108AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag108[] = {
	sFlag108Sprites1,
	sFlag108Sprites2,
	sFlag108Sprites3,
	sFlag108Sprites4,
	sFlag108Sprites5,
	sFlag108Sprites6,
};

static const axmain sAxMainFlag108 = {
	.poses = sAxPosesFlag108,
	.animations = sAxAnimationsFlag108,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag108),
	.spriteData = sAxSpritesFlag108,
	.positions = NULL,
};
const RGB gFlag109Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag109.pmdpal") };

static const axmain sAxMainFlag109;
const SiroArchive gAxFlag109 = {"SIRO", &sAxMainFlag109};

static const ax_pose sFlag109Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag109Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag109Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag109Gfx1[] = INCBIN_U8("graphics/ornament/Flag109/sprite_1.4bpp");
static const ax_sprite sFlag109Sprites1[] = {
	{sFlag109Gfx1, ARRAY_COUNT(sFlag109Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx2[] = INCBIN_U8("graphics/ornament/Flag109/sprite_2.4bpp");
static const ax_sprite sFlag109Sprites2[] = {
	{sFlag109Gfx2, ARRAY_COUNT(sFlag109Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx3[] = INCBIN_U8("graphics/ornament/Flag109/sprite_3.4bpp");
static const ax_sprite sFlag109Sprites3[] = {
	{sFlag109Gfx3, ARRAY_COUNT(sFlag109Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx4[] = INCBIN_U8("graphics/ornament/Flag109/sprite_4.4bpp");
static const ax_sprite sFlag109Sprites4[] = {
	{sFlag109Gfx4, ARRAY_COUNT(sFlag109Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx5[] = INCBIN_U8("graphics/ornament/Flag109/sprite_5.4bpp");
static const ax_sprite sFlag109Sprites5[] = {
	{sFlag109Gfx5, ARRAY_COUNT(sFlag109Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag109Gfx6[] = INCBIN_U8("graphics/ornament/Flag109/sprite_6.4bpp");
static const ax_sprite sFlag109Sprites6[] = {
	{sFlag109Gfx6, ARRAY_COUNT(sFlag109Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag109[] = {
	sFlag109Pose1,
	sFlag109Pose2,
	sFlag109Pose3,
	sFlag109Pose4,
	sFlag109Pose5,
	sFlag109Pose6,
};

static const ax_anim *const sFlag109AnimTable1[] = {
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
	sFlag109Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag109[] = {
	sFlag109AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag109[] = {
	sFlag109Sprites1,
	sFlag109Sprites2,
	sFlag109Sprites3,
	sFlag109Sprites4,
	sFlag109Sprites5,
	sFlag109Sprites6,
};

static const axmain sAxMainFlag109 = {
	.poses = sAxPosesFlag109,
	.animations = sAxAnimationsFlag109,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag109),
	.spriteData = sAxSpritesFlag109,
	.positions = NULL,
};
const RGB gFlag10Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag10.pmdpal") };

static const axmain sAxMainFlag10;
const SiroArchive gAxFlag10 = {"SIRO", &sAxMainFlag10};

static const ax_pose sFlag10Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag10Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag10Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag10Gfx1[] = INCBIN_U8("graphics/ornament/Flag10/sprite_1.4bpp");
static const ax_sprite sFlag10Sprites1[] = {
	{sFlag10Gfx1, ARRAY_COUNT(sFlag10Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx2[] = INCBIN_U8("graphics/ornament/Flag10/sprite_2.4bpp");
static const ax_sprite sFlag10Sprites2[] = {
	{sFlag10Gfx2, ARRAY_COUNT(sFlag10Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx3[] = INCBIN_U8("graphics/ornament/Flag10/sprite_3.4bpp");
static const ax_sprite sFlag10Sprites3[] = {
	{sFlag10Gfx3, ARRAY_COUNT(sFlag10Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx4[] = INCBIN_U8("graphics/ornament/Flag10/sprite_4.4bpp");
static const ax_sprite sFlag10Sprites4[] = {
	{sFlag10Gfx4, ARRAY_COUNT(sFlag10Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx5[] = INCBIN_U8("graphics/ornament/Flag10/sprite_5.4bpp");
static const ax_sprite sFlag10Sprites5[] = {
	{sFlag10Gfx5, ARRAY_COUNT(sFlag10Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag10Gfx6[] = INCBIN_U8("graphics/ornament/Flag10/sprite_6.4bpp");
static const ax_sprite sFlag10Sprites6[] = {
	{sFlag10Gfx6, ARRAY_COUNT(sFlag10Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag10[] = {
	sFlag10Pose1,
	sFlag10Pose2,
	sFlag10Pose3,
	sFlag10Pose4,
	sFlag10Pose5,
	sFlag10Pose6,
};

static const ax_anim *const sFlag10AnimTable1[] = {
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
	sFlag10Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag10[] = {
	sFlag10AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag10[] = {
	sFlag10Sprites1,
	sFlag10Sprites2,
	sFlag10Sprites3,
	sFlag10Sprites4,
	sFlag10Sprites5,
	sFlag10Sprites6,
};

static const axmain sAxMainFlag10 = {
	.poses = sAxPosesFlag10,
	.animations = sAxAnimationsFlag10,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag10),
	.spriteData = sAxSpritesFlag10,
	.positions = NULL,
};
const RGB gFlag110Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag110.pmdpal") };

static const axmain sAxMainFlag110;
const SiroArchive gAxFlag110 = {"SIRO", &sAxMainFlag110};

static const ax_pose sFlag110Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag110Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag110Gfx1[] = INCBIN_U8("graphics/ornament/Flag110/sprite_1.4bpp");
static const ax_sprite sFlag110Sprites1[] = {
	{sFlag110Gfx1, ARRAY_COUNT(sFlag110Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx2[] = INCBIN_U8("graphics/ornament/Flag110/sprite_2.4bpp");
static const ax_sprite sFlag110Sprites2[] = {
	{sFlag110Gfx2, ARRAY_COUNT(sFlag110Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx3[] = INCBIN_U8("graphics/ornament/Flag110/sprite_3.4bpp");
static const ax_sprite sFlag110Sprites3[] = {
	{sFlag110Gfx3, ARRAY_COUNT(sFlag110Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx4[] = INCBIN_U8("graphics/ornament/Flag110/sprite_4.4bpp");
static const ax_sprite sFlag110Sprites4[] = {
	{sFlag110Gfx4, ARRAY_COUNT(sFlag110Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx5[] = INCBIN_U8("graphics/ornament/Flag110/sprite_5.4bpp");
static const ax_sprite sFlag110Sprites5[] = {
	{sFlag110Gfx5, ARRAY_COUNT(sFlag110Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx6[] = INCBIN_U8("graphics/ornament/Flag110/sprite_6.4bpp");
static const ax_sprite sFlag110Sprites6[] = {
	{sFlag110Gfx6, ARRAY_COUNT(sFlag110Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag110[] = {
	sFlag110Pose1,
	sFlag110Pose2,
	sFlag110Pose3,
	sFlag110Pose4,
	sFlag110Pose5,
	sFlag110Pose6,
};

static const ax_anim *const sFlag110AnimTable1[] = {
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag110[] = {
	sFlag110AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag110[] = {
	sFlag110Sprites1,
	sFlag110Sprites2,
	sFlag110Sprites3,
	sFlag110Sprites4,
	sFlag110Sprites5,
	sFlag110Sprites6,
};

static const axmain sAxMainFlag110 = {
	.poses = sAxPosesFlag110,
	.animations = sAxAnimationsFlag110,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag110),
	.spriteData = sAxSpritesFlag110,
	.positions = NULL,
};
const RGB gFlag111Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag111.pmdpal") };

static const axmain sAxMainFlag111;
const SiroArchive gAxFlag111 = {"SIRO", &sAxMainFlag111};

static const ax_pose sFlag111Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag111Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag111Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag111Gfx1[] = INCBIN_U8("graphics/ornament/Flag111/sprite_1.4bpp");
static const ax_sprite sFlag111Sprites1[] = {
	{sFlag111Gfx1, ARRAY_COUNT(sFlag111Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx2[] = INCBIN_U8("graphics/ornament/Flag111/sprite_2.4bpp");
static const ax_sprite sFlag111Sprites2[] = {
	{sFlag111Gfx2, ARRAY_COUNT(sFlag111Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx3[] = INCBIN_U8("graphics/ornament/Flag111/sprite_3.4bpp");
static const ax_sprite sFlag111Sprites3[] = {
	{sFlag111Gfx3, ARRAY_COUNT(sFlag111Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx4[] = INCBIN_U8("graphics/ornament/Flag111/sprite_4.4bpp");
static const ax_sprite sFlag111Sprites4[] = {
	{sFlag111Gfx4, ARRAY_COUNT(sFlag111Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx5[] = INCBIN_U8("graphics/ornament/Flag111/sprite_5.4bpp");
static const ax_sprite sFlag111Sprites5[] = {
	{sFlag111Gfx5, ARRAY_COUNT(sFlag111Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag111Gfx6[] = INCBIN_U8("graphics/ornament/Flag111/sprite_6.4bpp");
static const ax_sprite sFlag111Sprites6[] = {
	{sFlag111Gfx6, ARRAY_COUNT(sFlag111Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag111[] = {
	sFlag111Pose1,
	sFlag111Pose2,
	sFlag111Pose3,
	sFlag111Pose4,
	sFlag111Pose5,
	sFlag111Pose6,
};

static const ax_anim *const sFlag111AnimTable1[] = {
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
	sFlag111Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag111[] = {
	sFlag111AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag111[] = {
	sFlag111Sprites1,
	sFlag111Sprites2,
	sFlag111Sprites3,
	sFlag111Sprites4,
	sFlag111Sprites5,
	sFlag111Sprites6,
};

static const axmain sAxMainFlag111 = {
	.poses = sAxPosesFlag111,
	.animations = sAxAnimationsFlag111,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag111),
	.spriteData = sAxSpritesFlag111,
	.positions = NULL,
};
const RGB gFlag112Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag112.pmdpal") };

static const axmain sAxMainFlag112;
const SiroArchive gAxFlag112 = {"SIRO", &sAxMainFlag112};

static const ax_pose sFlag112Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag112Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag112Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag112Gfx1[] = INCBIN_U8("graphics/ornament/Flag112/sprite_1.4bpp");
static const ax_sprite sFlag112Sprites1[] = {
	{sFlag112Gfx1, ARRAY_COUNT(sFlag112Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx2[] = INCBIN_U8("graphics/ornament/Flag112/sprite_2.4bpp");
static const ax_sprite sFlag112Sprites2[] = {
	{sFlag112Gfx2, ARRAY_COUNT(sFlag112Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx3[] = INCBIN_U8("graphics/ornament/Flag112/sprite_3.4bpp");
static const ax_sprite sFlag112Sprites3[] = {
	{sFlag112Gfx3, ARRAY_COUNT(sFlag112Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx4[] = INCBIN_U8("graphics/ornament/Flag112/sprite_4.4bpp");
static const ax_sprite sFlag112Sprites4[] = {
	{sFlag112Gfx4, ARRAY_COUNT(sFlag112Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx5[] = INCBIN_U8("graphics/ornament/Flag112/sprite_5.4bpp");
static const ax_sprite sFlag112Sprites5[] = {
	{sFlag112Gfx5, ARRAY_COUNT(sFlag112Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag112Gfx6[] = INCBIN_U8("graphics/ornament/Flag112/sprite_6.4bpp");
static const ax_sprite sFlag112Sprites6[] = {
	{sFlag112Gfx6, ARRAY_COUNT(sFlag112Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag112[] = {
	sFlag112Pose1,
	sFlag112Pose2,
	sFlag112Pose3,
	sFlag112Pose4,
	sFlag112Pose5,
	sFlag112Pose6,
};

static const ax_anim *const sFlag112AnimTable1[] = {
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
	sFlag112Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag112[] = {
	sFlag112AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag112[] = {
	sFlag112Sprites1,
	sFlag112Sprites2,
	sFlag112Sprites3,
	sFlag112Sprites4,
	sFlag112Sprites5,
	sFlag112Sprites6,
};

static const axmain sAxMainFlag112 = {
	.poses = sAxPosesFlag112,
	.animations = sAxAnimationsFlag112,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag112),
	.spriteData = sAxSpritesFlag112,
	.positions = NULL,
};
