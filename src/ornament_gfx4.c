#include "global.h"
#include "globaldata.h"
#include "ornament_gfx.h"

const RGB gFlag113Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag113.pmdpal") };

static const axmain sAxMainFlag113;
const SiroArchive gAxFlag113 = {"SIRO", &sAxMainFlag113};

static const ax_pose sFlag113Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag113Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag113Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag113Gfx1[] = INCBIN_U8("graphics/ornament/Flag113/sprite_1.4bpp");
static const ax_sprite sFlag113Sprites1[] = {
	{sFlag113Gfx1, ARRAY_COUNT(sFlag113Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx2[] = INCBIN_U8("graphics/ornament/Flag113/sprite_2.4bpp");
static const ax_sprite sFlag113Sprites2[] = {
	{sFlag113Gfx2, ARRAY_COUNT(sFlag113Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx3[] = INCBIN_U8("graphics/ornament/Flag113/sprite_3.4bpp");
static const ax_sprite sFlag113Sprites3[] = {
	{sFlag113Gfx3, ARRAY_COUNT(sFlag113Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx4[] = INCBIN_U8("graphics/ornament/Flag113/sprite_4.4bpp");
static const ax_sprite sFlag113Sprites4[] = {
	{sFlag113Gfx4, ARRAY_COUNT(sFlag113Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx5[] = INCBIN_U8("graphics/ornament/Flag113/sprite_5.4bpp");
static const ax_sprite sFlag113Sprites5[] = {
	{sFlag113Gfx5, ARRAY_COUNT(sFlag113Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag113Gfx6[] = INCBIN_U8("graphics/ornament/Flag113/sprite_6.4bpp");
static const ax_sprite sFlag113Sprites6[] = {
	{sFlag113Gfx6, ARRAY_COUNT(sFlag113Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag113[] = {
	sFlag113Pose1,
	sFlag113Pose2,
	sFlag113Pose3,
	sFlag113Pose4,
	sFlag113Pose5,
	sFlag113Pose6,
};

static const ax_anim *const sFlag113AnimTable1[] = {
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
	sFlag113Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag113[] = {
	sFlag113AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag113[] = {
	sFlag113Sprites1,
	sFlag113Sprites2,
	sFlag113Sprites3,
	sFlag113Sprites4,
	sFlag113Sprites5,
	sFlag113Sprites6,
};

static const axmain sAxMainFlag113 = {
	.poses = sAxPosesFlag113,
	.animations = sAxAnimationsFlag113,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag113),
	.spriteData = sAxSpritesFlag113,
	.positions = NULL,
};
const RGB gFlag114Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag114.pmdpal") };

static const axmain sAxMainFlag114;
const SiroArchive gAxFlag114 = {"SIRO", &sAxMainFlag114};

static const ax_pose sFlag114Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag114Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag114Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag114Gfx1[] = INCBIN_U8("graphics/ornament/Flag114/sprite_1.4bpp");
static const ax_sprite sFlag114Sprites1[] = {
	{sFlag114Gfx1, ARRAY_COUNT(sFlag114Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx2[] = INCBIN_U8("graphics/ornament/Flag114/sprite_2.4bpp");
static const ax_sprite sFlag114Sprites2[] = {
	{sFlag114Gfx2, ARRAY_COUNT(sFlag114Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx3[] = INCBIN_U8("graphics/ornament/Flag114/sprite_3.4bpp");
static const ax_sprite sFlag114Sprites3[] = {
	{sFlag114Gfx3, ARRAY_COUNT(sFlag114Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx4[] = INCBIN_U8("graphics/ornament/Flag114/sprite_4.4bpp");
static const ax_sprite sFlag114Sprites4[] = {
	{sFlag114Gfx4, ARRAY_COUNT(sFlag114Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx5[] = INCBIN_U8("graphics/ornament/Flag114/sprite_5.4bpp");
static const ax_sprite sFlag114Sprites5[] = {
	{sFlag114Gfx5, ARRAY_COUNT(sFlag114Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag114Gfx6[] = INCBIN_U8("graphics/ornament/Flag114/sprite_6.4bpp");
static const ax_sprite sFlag114Sprites6[] = {
	{sFlag114Gfx6, ARRAY_COUNT(sFlag114Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag114[] = {
	sFlag114Pose1,
	sFlag114Pose2,
	sFlag114Pose3,
	sFlag114Pose4,
	sFlag114Pose5,
	sFlag114Pose6,
};

static const ax_anim *const sFlag114AnimTable1[] = {
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
	sFlag114Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag114[] = {
	sFlag114AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag114[] = {
	sFlag114Sprites1,
	sFlag114Sprites2,
	sFlag114Sprites3,
	sFlag114Sprites4,
	sFlag114Sprites5,
	sFlag114Sprites6,
};

static const axmain sAxMainFlag114 = {
	.poses = sAxPosesFlag114,
	.animations = sAxAnimationsFlag114,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag114),
	.spriteData = sAxSpritesFlag114,
	.positions = NULL,
};
const RGB gFlag11Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag11.pmdpal") };

static const axmain sAxMainFlag11;
const SiroArchive gAxFlag11 = {"SIRO", &sAxMainFlag11};

static const ax_pose sFlag11Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag11Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag11Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag11Gfx1[] = INCBIN_U8("graphics/ornament/Flag11/sprite_1.4bpp");
static const ax_sprite sFlag11Sprites1[] = {
	{sFlag11Gfx1, ARRAY_COUNT(sFlag11Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx2[] = INCBIN_U8("graphics/ornament/Flag11/sprite_2.4bpp");
static const ax_sprite sFlag11Sprites2[] = {
	{sFlag11Gfx2, ARRAY_COUNT(sFlag11Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx3[] = INCBIN_U8("graphics/ornament/Flag11/sprite_3.4bpp");
static const ax_sprite sFlag11Sprites3[] = {
	{sFlag11Gfx3, ARRAY_COUNT(sFlag11Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx4[] = INCBIN_U8("graphics/ornament/Flag11/sprite_4.4bpp");
static const ax_sprite sFlag11Sprites4[] = {
	{sFlag11Gfx4, ARRAY_COUNT(sFlag11Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx5[] = INCBIN_U8("graphics/ornament/Flag11/sprite_5.4bpp");
static const ax_sprite sFlag11Sprites5[] = {
	{sFlag11Gfx5, ARRAY_COUNT(sFlag11Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag11Gfx6[] = INCBIN_U8("graphics/ornament/Flag11/sprite_6.4bpp");
static const ax_sprite sFlag11Sprites6[] = {
	{sFlag11Gfx6, ARRAY_COUNT(sFlag11Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag11[] = {
	sFlag11Pose1,
	sFlag11Pose2,
	sFlag11Pose3,
	sFlag11Pose4,
	sFlag11Pose5,
	sFlag11Pose6,
};

static const ax_anim *const sFlag11AnimTable1[] = {
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
	sFlag11Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag11[] = {
	sFlag11AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag11[] = {
	sFlag11Sprites1,
	sFlag11Sprites2,
	sFlag11Sprites3,
	sFlag11Sprites4,
	sFlag11Sprites5,
	sFlag11Sprites6,
};

static const axmain sAxMainFlag11 = {
	.poses = sAxPosesFlag11,
	.animations = sAxAnimationsFlag11,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag11),
	.spriteData = sAxSpritesFlag11,
	.positions = NULL,
};
const RGB gFlag12Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag12.pmdpal") };

static const axmain sAxMainFlag12;
const SiroArchive gAxFlag12 = {"SIRO", &sAxMainFlag12};

static const ax_pose sFlag12Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag12Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag12Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag12Gfx1[] = INCBIN_U8("graphics/ornament/Flag12/sprite_1.4bpp");
static const ax_sprite sFlag12Sprites1[] = {
	{sFlag12Gfx1, ARRAY_COUNT(sFlag12Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx2[] = INCBIN_U8("graphics/ornament/Flag12/sprite_2.4bpp");
static const ax_sprite sFlag12Sprites2[] = {
	{sFlag12Gfx2, ARRAY_COUNT(sFlag12Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx3[] = INCBIN_U8("graphics/ornament/Flag12/sprite_3.4bpp");
static const ax_sprite sFlag12Sprites3[] = {
	{sFlag12Gfx3, ARRAY_COUNT(sFlag12Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx4[] = INCBIN_U8("graphics/ornament/Flag12/sprite_4.4bpp");
static const ax_sprite sFlag12Sprites4[] = {
	{sFlag12Gfx4, ARRAY_COUNT(sFlag12Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx5[] = INCBIN_U8("graphics/ornament/Flag12/sprite_5.4bpp");
static const ax_sprite sFlag12Sprites5[] = {
	{sFlag12Gfx5, ARRAY_COUNT(sFlag12Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag12Gfx6[] = INCBIN_U8("graphics/ornament/Flag12/sprite_6.4bpp");
static const ax_sprite sFlag12Sprites6[] = {
	{sFlag12Gfx6, ARRAY_COUNT(sFlag12Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag12[] = {
	sFlag12Pose1,
	sFlag12Pose2,
	sFlag12Pose3,
	sFlag12Pose4,
	sFlag12Pose5,
	sFlag12Pose6,
};

static const ax_anim *const sFlag12AnimTable1[] = {
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
	sFlag12Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag12[] = {
	sFlag12AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag12[] = {
	sFlag12Sprites1,
	sFlag12Sprites2,
	sFlag12Sprites3,
	sFlag12Sprites4,
	sFlag12Sprites5,
	sFlag12Sprites6,
};

static const axmain sAxMainFlag12 = {
	.poses = sAxPosesFlag12,
	.animations = sAxAnimationsFlag12,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag12),
	.spriteData = sAxSpritesFlag12,
	.positions = NULL,
};
const RGB gFlag13Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag13.pmdpal") };

static const axmain sAxMainFlag13;
const SiroArchive gAxFlag13 = {"SIRO", &sAxMainFlag13};

static const ax_pose sFlag13Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag13Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag13Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag13Gfx1[] = INCBIN_U8("graphics/ornament/Flag13/sprite_1.4bpp");
static const ax_sprite sFlag13Sprites1[] = {
	{sFlag13Gfx1, ARRAY_COUNT(sFlag13Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx2[] = INCBIN_U8("graphics/ornament/Flag13/sprite_2.4bpp");
static const ax_sprite sFlag13Sprites2[] = {
	{sFlag13Gfx2, ARRAY_COUNT(sFlag13Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx3[] = INCBIN_U8("graphics/ornament/Flag13/sprite_3.4bpp");
static const ax_sprite sFlag13Sprites3[] = {
	{sFlag13Gfx3, ARRAY_COUNT(sFlag13Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx4[] = INCBIN_U8("graphics/ornament/Flag13/sprite_4.4bpp");
static const ax_sprite sFlag13Sprites4[] = {
	{sFlag13Gfx4, ARRAY_COUNT(sFlag13Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx5[] = INCBIN_U8("graphics/ornament/Flag13/sprite_5.4bpp");
static const ax_sprite sFlag13Sprites5[] = {
	{sFlag13Gfx5, ARRAY_COUNT(sFlag13Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag13Gfx6[] = INCBIN_U8("graphics/ornament/Flag13/sprite_6.4bpp");
static const ax_sprite sFlag13Sprites6[] = {
	{sFlag13Gfx6, ARRAY_COUNT(sFlag13Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag13[] = {
	sFlag13Pose1,
	sFlag13Pose2,
	sFlag13Pose3,
	sFlag13Pose4,
	sFlag13Pose5,
	sFlag13Pose6,
};

static const ax_anim *const sFlag13AnimTable1[] = {
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
	sFlag13Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag13[] = {
	sFlag13AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag13[] = {
	sFlag13Sprites1,
	sFlag13Sprites2,
	sFlag13Sprites3,
	sFlag13Sprites4,
	sFlag13Sprites5,
	sFlag13Sprites6,
};

static const axmain sAxMainFlag13 = {
	.poses = sAxPosesFlag13,
	.animations = sAxAnimationsFlag13,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag13),
	.spriteData = sAxSpritesFlag13,
	.positions = NULL,
};
const RGB gFlag14Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag14.pmdpal") };

static const axmain sAxMainFlag14;
const SiroArchive gAxFlag14 = {"SIRO", &sAxMainFlag14};

static const ax_pose sFlag14Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag14Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag14Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag14Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag14Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag14Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag14Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag14Gfx1[] = INCBIN_U8("graphics/ornament/Flag14/sprite_1.4bpp");
static const ax_sprite sFlag14Sprites1[] = {
	{sFlag14Gfx1, ARRAY_COUNT(sFlag14Gfx1)},
	{NULL, 160},
	{NULL, 0},
};
static const u8 sFlag14Gfx2[] = INCBIN_U8("graphics/ornament/Flag14/sprite_2.4bpp");
static const u8 sFlag14Gfx2_2[] = INCBIN_U8("graphics/ornament/Flag14/sprite_2_2.4bpp");
static const ax_sprite sFlag14Sprites2[] = {
	{sFlag14Gfx2, ARRAY_COUNT(sFlag14Gfx2)},
	{NULL, 32},
	{sFlag14Gfx2_2, ARRAY_COUNT(sFlag14Gfx2_2)},
	{NULL, 160},
	{NULL, 0},
};
static const u8 sFlag14Gfx3[] = INCBIN_U8("graphics/ornament/Flag14/sprite_3.4bpp");
static const u8 sFlag14Gfx3_2[] = INCBIN_U8("graphics/ornament/Flag14/sprite_3_2.4bpp");
static const ax_sprite sFlag14Sprites3[] = {
	{sFlag14Gfx3, ARRAY_COUNT(sFlag14Gfx3)},
	{NULL, 32},
	{sFlag14Gfx3_2, ARRAY_COUNT(sFlag14Gfx3_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag14Gfx4[] = INCBIN_U8("graphics/ornament/Flag14/sprite_4.4bpp");
static const u8 sFlag14Gfx4_2[] = INCBIN_U8("graphics/ornament/Flag14/sprite_4_2.4bpp");
static const ax_sprite sFlag14Sprites4[] = {
	{sFlag14Gfx4, ARRAY_COUNT(sFlag14Gfx4)},
	{NULL, 32},
	{sFlag14Gfx4_2, ARRAY_COUNT(sFlag14Gfx4_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag14Gfx5[] = INCBIN_U8("graphics/ornament/Flag14/sprite_5.4bpp");
static const u8 sFlag14Gfx5_2[] = INCBIN_U8("graphics/ornament/Flag14/sprite_5_2.4bpp");
static const ax_sprite sFlag14Sprites5[] = {
	{sFlag14Gfx5, ARRAY_COUNT(sFlag14Gfx5)},
	{NULL, 32},
	{sFlag14Gfx5_2, ARRAY_COUNT(sFlag14Gfx5_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag14Gfx6[] = INCBIN_U8("graphics/ornament/Flag14/sprite_6.4bpp");
static const ax_sprite sFlag14Sprites6[] = {
	{sFlag14Gfx6, ARRAY_COUNT(sFlag14Gfx6)},
	{NULL, 160},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag14[] = {
	sFlag14Pose1,
	sFlag14Pose2,
	sFlag14Pose3,
	sFlag14Pose4,
	sFlag14Pose5,
	sFlag14Pose6,
};

static const ax_anim *const sFlag14AnimTable1[] = {
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
	sFlag14Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag14[] = {
	sFlag14AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag14[] = {
	sFlag14Sprites1,
	sFlag14Sprites2,
	sFlag14Sprites3,
	sFlag14Sprites4,
	sFlag14Sprites5,
	sFlag14Sprites6,
};

static const axmain sAxMainFlag14 = {
	.poses = sAxPosesFlag14,
	.animations = sAxAnimationsFlag14,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag14),
	.spriteData = sAxSpritesFlag14,
	.positions = NULL,
};
const RGB gFlag15Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag15.pmdpal") };

static const axmain sAxMainFlag15;
const SiroArchive gAxFlag15 = {"SIRO", &sAxMainFlag15};

static const ax_pose sFlag15Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag15Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag15Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag15Gfx1[] = INCBIN_U8("graphics/ornament/Flag15/sprite_1.4bpp");
static const ax_sprite sFlag15Sprites1[] = {
	{sFlag15Gfx1, ARRAY_COUNT(sFlag15Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx2[] = INCBIN_U8("graphics/ornament/Flag15/sprite_2.4bpp");
static const ax_sprite sFlag15Sprites2[] = {
	{sFlag15Gfx2, ARRAY_COUNT(sFlag15Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx3[] = INCBIN_U8("graphics/ornament/Flag15/sprite_3.4bpp");
static const ax_sprite sFlag15Sprites3[] = {
	{sFlag15Gfx3, ARRAY_COUNT(sFlag15Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx4[] = INCBIN_U8("graphics/ornament/Flag15/sprite_4.4bpp");
static const ax_sprite sFlag15Sprites4[] = {
	{sFlag15Gfx4, ARRAY_COUNT(sFlag15Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx5[] = INCBIN_U8("graphics/ornament/Flag15/sprite_5.4bpp");
static const ax_sprite sFlag15Sprites5[] = {
	{sFlag15Gfx5, ARRAY_COUNT(sFlag15Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag15Gfx6[] = INCBIN_U8("graphics/ornament/Flag15/sprite_6.4bpp");
static const ax_sprite sFlag15Sprites6[] = {
	{sFlag15Gfx6, ARRAY_COUNT(sFlag15Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag15[] = {
	sFlag15Pose1,
	sFlag15Pose2,
	sFlag15Pose3,
	sFlag15Pose4,
	sFlag15Pose5,
	sFlag15Pose6,
};

static const ax_anim *const sFlag15AnimTable1[] = {
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
	sFlag15Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag15[] = {
	sFlag15AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag15[] = {
	sFlag15Sprites1,
	sFlag15Sprites2,
	sFlag15Sprites3,
	sFlag15Sprites4,
	sFlag15Sprites5,
	sFlag15Sprites6,
};

static const axmain sAxMainFlag15 = {
	.poses = sAxPosesFlag15,
	.animations = sAxAnimationsFlag15,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag15),
	.spriteData = sAxSpritesFlag15,
	.positions = NULL,
};
const RGB gFlag16Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag16.pmdpal") };

static const axmain sAxMainFlag16;
const SiroArchive gAxFlag16 = {"SIRO", &sAxMainFlag16};

static const ax_pose sFlag16Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag16Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag16Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag16Gfx1[] = INCBIN_U8("graphics/ornament/Flag16/sprite_1.4bpp");
static const ax_sprite sFlag16Sprites1[] = {
	{sFlag16Gfx1, ARRAY_COUNT(sFlag16Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx2[] = INCBIN_U8("graphics/ornament/Flag16/sprite_2.4bpp");
static const ax_sprite sFlag16Sprites2[] = {
	{sFlag16Gfx2, ARRAY_COUNT(sFlag16Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx3[] = INCBIN_U8("graphics/ornament/Flag16/sprite_3.4bpp");
static const ax_sprite sFlag16Sprites3[] = {
	{sFlag16Gfx3, ARRAY_COUNT(sFlag16Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx4[] = INCBIN_U8("graphics/ornament/Flag16/sprite_4.4bpp");
static const ax_sprite sFlag16Sprites4[] = {
	{sFlag16Gfx4, ARRAY_COUNT(sFlag16Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx5[] = INCBIN_U8("graphics/ornament/Flag16/sprite_5.4bpp");
static const ax_sprite sFlag16Sprites5[] = {
	{sFlag16Gfx5, ARRAY_COUNT(sFlag16Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag16Gfx6[] = INCBIN_U8("graphics/ornament/Flag16/sprite_6.4bpp");
static const ax_sprite sFlag16Sprites6[] = {
	{sFlag16Gfx6, ARRAY_COUNT(sFlag16Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag16[] = {
	sFlag16Pose1,
	sFlag16Pose2,
	sFlag16Pose3,
	sFlag16Pose4,
	sFlag16Pose5,
	sFlag16Pose6,
};

static const ax_anim *const sFlag16AnimTable1[] = {
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
	sFlag16Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag16[] = {
	sFlag16AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag16[] = {
	sFlag16Sprites1,
	sFlag16Sprites2,
	sFlag16Sprites3,
	sFlag16Sprites4,
	sFlag16Sprites5,
	sFlag16Sprites6,
};

static const axmain sAxMainFlag16 = {
	.poses = sAxPosesFlag16,
	.animations = sAxAnimationsFlag16,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag16),
	.spriteData = sAxSpritesFlag16,
	.positions = NULL,
};
