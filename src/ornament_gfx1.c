#include "global.h"
#include "globaldata.h"
#include "ornament_gfx.h"

const RGB gFlag00Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag00.pmdpal") };

static const axmain sAxMainFlag00;
const SiroArchive gAxFlag00 = {"SIRO", &sAxMainFlag00};

static const ax_pose sFlag00Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag00Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag00Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag00Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag00Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag00Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag00Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag00Gfx1[] = INCBIN_U8("graphics/ornament/Flag00/sprite_1.4bpp");
static const ax_sprite sFlag00Sprites1[] = {
	{sFlag00Gfx1, ARRAY_COUNT(sFlag00Gfx1)},
	{NULL, 352},
	{NULL, 0},
};
static const u8 sFlag00Gfx2[] = INCBIN_U8("graphics/ornament/Flag00/sprite_2.4bpp");
static const ax_sprite sFlag00Sprites2[] = {
	{sFlag00Gfx2, ARRAY_COUNT(sFlag00Gfx2)},
	{NULL, 320},
	{NULL, 0},
};
static const u8 sFlag00Gfx3[] = INCBIN_U8("graphics/ornament/Flag00/sprite_3.4bpp");
static const ax_sprite sFlag00Sprites3[] = {
	{sFlag00Gfx3, ARRAY_COUNT(sFlag00Gfx3)},
	{NULL, 288},
	{NULL, 0},
};
static const u8 sFlag00Gfx4[] = INCBIN_U8("graphics/ornament/Flag00/sprite_4.4bpp");
static const ax_sprite sFlag00Sprites4[] = {
	{sFlag00Gfx4, ARRAY_COUNT(sFlag00Gfx4)},
	{NULL, 352},
	{NULL, 0},
};
static const u8 sFlag00Gfx5[] = INCBIN_U8("graphics/ornament/Flag00/sprite_5.4bpp");
static const ax_sprite sFlag00Sprites5[] = {
	{sFlag00Gfx5, ARRAY_COUNT(sFlag00Gfx5)},
	{NULL, 352},
	{NULL, 0},
};
static const u8 sFlag00Gfx6[] = INCBIN_U8("graphics/ornament/Flag00/sprite_6.4bpp");
static const u8 sFlag00Gfx6_2[] = INCBIN_U8("graphics/ornament/Flag00/sprite_6_2.4bpp");
static const ax_sprite sFlag00Sprites6[] = {
	{sFlag00Gfx6, ARRAY_COUNT(sFlag00Gfx6)},
	{NULL, 64},
	{sFlag00Gfx6_2, ARRAY_COUNT(sFlag00Gfx6_2)},
	{NULL, 256},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag00[] = {
	sFlag00Pose1,
	sFlag00Pose2,
	sFlag00Pose3,
	sFlag00Pose4,
	sFlag00Pose5,
	sFlag00Pose6,
};

static const ax_anim *const sFlag00AnimTable1[] = {
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
	sFlag00Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag00[] = {
	sFlag00AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag00[] = {
	sFlag00Sprites1,
	sFlag00Sprites2,
	sFlag00Sprites3,
	sFlag00Sprites4,
	sFlag00Sprites5,
	sFlag00Sprites6,
};

static const axmain sAxMainFlag00 = {
	.poses = sAxPosesFlag00,
	.animations = sAxAnimationsFlag00,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag00),
	.spriteData = sAxSpritesFlag00,
	.positions = NULL,
};
const RGB gFlag01Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag01.pmdpal") };

static const axmain sAxMainFlag01;
const SiroArchive gAxFlag01 = {"SIRO", &sAxMainFlag01};

static const ax_pose sFlag01Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag01Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag01Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag01Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag01Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag01Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag01Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag01Gfx1[] = INCBIN_U8("graphics/ornament/Flag01/sprite_1.4bpp");
static const u8 sFlag01Gfx1_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_1_2.4bpp");
static const ax_sprite sFlag01Sprites1[] = {
	{sFlag01Gfx1, ARRAY_COUNT(sFlag01Gfx1)},
	{NULL, 32},
	{sFlag01Gfx1_2, ARRAY_COUNT(sFlag01Gfx1_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag01Gfx2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_2.4bpp");
static const u8 sFlag01Gfx2_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_2_2.4bpp");
static const ax_sprite sFlag01Sprites2[] = {
	{sFlag01Gfx2, ARRAY_COUNT(sFlag01Gfx2)},
	{NULL, 32},
	{sFlag01Gfx2_2, ARRAY_COUNT(sFlag01Gfx2_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag01Gfx3[] = INCBIN_U8("graphics/ornament/Flag01/sprite_3.4bpp");
static const u8 sFlag01Gfx3_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_3_2.4bpp");
static const ax_sprite sFlag01Sprites3[] = {
	{sFlag01Gfx3, ARRAY_COUNT(sFlag01Gfx3)},
	{NULL, 32},
	{sFlag01Gfx3_2, ARRAY_COUNT(sFlag01Gfx3_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag01Gfx4[] = INCBIN_U8("graphics/ornament/Flag01/sprite_4.4bpp");
static const u8 sFlag01Gfx4_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_4_2.4bpp");
static const ax_sprite sFlag01Sprites4[] = {
	{sFlag01Gfx4, ARRAY_COUNT(sFlag01Gfx4)},
	{NULL, 32},
	{sFlag01Gfx4_2, ARRAY_COUNT(sFlag01Gfx4_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag01Gfx5[] = INCBIN_U8("graphics/ornament/Flag01/sprite_5.4bpp");
static const u8 sFlag01Gfx5_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_5_2.4bpp");
static const ax_sprite sFlag01Sprites5[] = {
	{sFlag01Gfx5, ARRAY_COUNT(sFlag01Gfx5)},
	{NULL, 32},
	{sFlag01Gfx5_2, ARRAY_COUNT(sFlag01Gfx5_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag01Gfx6[] = INCBIN_U8("graphics/ornament/Flag01/sprite_6.4bpp");
static const u8 sFlag01Gfx6_2[] = INCBIN_U8("graphics/ornament/Flag01/sprite_6_2.4bpp");
static const ax_sprite sFlag01Sprites6[] = {
	{sFlag01Gfx6, ARRAY_COUNT(sFlag01Gfx6)},
	{NULL, 32},
	{sFlag01Gfx6_2, ARRAY_COUNT(sFlag01Gfx6_2)},
	{NULL, 160},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag01[] = {
	sFlag01Pose1,
	sFlag01Pose2,
	sFlag01Pose3,
	sFlag01Pose4,
	sFlag01Pose5,
	sFlag01Pose6,
};

static const ax_anim *const sFlag01AnimTable1[] = {
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
	sFlag01Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag01[] = {
	sFlag01AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag01[] = {
	sFlag01Sprites1,
	sFlag01Sprites2,
	sFlag01Sprites3,
	sFlag01Sprites4,
	sFlag01Sprites5,
	sFlag01Sprites6,
};

static const axmain sAxMainFlag01 = {
	.poses = sAxPosesFlag01,
	.animations = sAxAnimationsFlag01,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag01),
	.spriteData = sAxSpritesFlag01,
	.positions = NULL,
};
const RGB gFlag02Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag02.pmdpal") };

static const axmain sAxMainFlag02;
const SiroArchive gAxFlag02 = {"SIRO", &sAxMainFlag02};

static const ax_pose sFlag02Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag02Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag02Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag02Gfx1[] = INCBIN_U8("graphics/ornament/Flag02/sprite_1.4bpp");
static const ax_sprite sFlag02Sprites1[] = {
	{sFlag02Gfx1, ARRAY_COUNT(sFlag02Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx2[] = INCBIN_U8("graphics/ornament/Flag02/sprite_2.4bpp");
static const ax_sprite sFlag02Sprites2[] = {
	{sFlag02Gfx2, ARRAY_COUNT(sFlag02Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx3[] = INCBIN_U8("graphics/ornament/Flag02/sprite_3.4bpp");
static const ax_sprite sFlag02Sprites3[] = {
	{sFlag02Gfx3, ARRAY_COUNT(sFlag02Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx4[] = INCBIN_U8("graphics/ornament/Flag02/sprite_4.4bpp");
static const ax_sprite sFlag02Sprites4[] = {
	{sFlag02Gfx4, ARRAY_COUNT(sFlag02Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx5[] = INCBIN_U8("graphics/ornament/Flag02/sprite_5.4bpp");
static const ax_sprite sFlag02Sprites5[] = {
	{sFlag02Gfx5, ARRAY_COUNT(sFlag02Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag02Gfx6[] = INCBIN_U8("graphics/ornament/Flag02/sprite_6.4bpp");
static const ax_sprite sFlag02Sprites6[] = {
	{sFlag02Gfx6, ARRAY_COUNT(sFlag02Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag02[] = {
	sFlag02Pose1,
	sFlag02Pose2,
	sFlag02Pose3,
	sFlag02Pose4,
	sFlag02Pose5,
	sFlag02Pose6,
};

static const ax_anim *const sFlag02AnimTable1[] = {
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
	sFlag02Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag02[] = {
	sFlag02AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag02[] = {
	sFlag02Sprites1,
	sFlag02Sprites2,
	sFlag02Sprites3,
	sFlag02Sprites4,
	sFlag02Sprites5,
	sFlag02Sprites6,
};

static const axmain sAxMainFlag02 = {
	.poses = sAxPosesFlag02,
	.animations = sAxAnimationsFlag02,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag02),
	.spriteData = sAxSpritesFlag02,
	.positions = NULL,
};
const RGB gFlag03Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag03.pmdpal") };

static const axmain sAxMainFlag03;
const SiroArchive gAxFlag03 = {"SIRO", &sAxMainFlag03};

static const ax_pose sFlag03Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag03Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag03Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag03Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag03Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag03Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag03Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag03Gfx1[] = INCBIN_U8("graphics/ornament/Flag03/sprite_1.4bpp");
static const u8 sFlag03Gfx1_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_1_2.4bpp");
static const ax_sprite sFlag03Sprites1[] = {
	{sFlag03Gfx1, ARRAY_COUNT(sFlag03Gfx1)},
	{NULL, 32},
	{sFlag03Gfx1_2, ARRAY_COUNT(sFlag03Gfx1_2)},
	{NULL, 160},
	{NULL, 0},
};
static const u8 sFlag03Gfx2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_2.4bpp");
static const u8 sFlag03Gfx2_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_2_2.4bpp");
static const ax_sprite sFlag03Sprites2[] = {
	{sFlag03Gfx2, ARRAY_COUNT(sFlag03Gfx2)},
	{NULL, 32},
	{sFlag03Gfx2_2, ARRAY_COUNT(sFlag03Gfx2_2)},
	{NULL, 160},
	{NULL, 0},
};
static const u8 sFlag03Gfx3[] = INCBIN_U8("graphics/ornament/Flag03/sprite_3.4bpp");
static const u8 sFlag03Gfx3_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_3_2.4bpp");
static const ax_sprite sFlag03Sprites3[] = {
	{sFlag03Gfx3, ARRAY_COUNT(sFlag03Gfx3)},
	{NULL, 32},
	{sFlag03Gfx3_2, ARRAY_COUNT(sFlag03Gfx3_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag03Gfx4[] = INCBIN_U8("graphics/ornament/Flag03/sprite_4.4bpp");
static const u8 sFlag03Gfx4_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_4_2.4bpp");
static const ax_sprite sFlag03Sprites4[] = {
	{sFlag03Gfx4, ARRAY_COUNT(sFlag03Gfx4)},
	{NULL, 32},
	{sFlag03Gfx4_2, ARRAY_COUNT(sFlag03Gfx4_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag03Gfx5[] = INCBIN_U8("graphics/ornament/Flag03/sprite_5.4bpp");
static const u8 sFlag03Gfx5_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_5_2.4bpp");
static const ax_sprite sFlag03Sprites5[] = {
	{sFlag03Gfx5, ARRAY_COUNT(sFlag03Gfx5)},
	{NULL, 32},
	{sFlag03Gfx5_2, ARRAY_COUNT(sFlag03Gfx5_2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag03Gfx6[] = INCBIN_U8("graphics/ornament/Flag03/sprite_6.4bpp");
static const u8 sFlag03Gfx6_2[] = INCBIN_U8("graphics/ornament/Flag03/sprite_6_2.4bpp");
static const ax_sprite sFlag03Sprites6[] = {
	{sFlag03Gfx6, ARRAY_COUNT(sFlag03Gfx6)},
	{NULL, 32},
	{sFlag03Gfx6_2, ARRAY_COUNT(sFlag03Gfx6_2)},
	{NULL, 160},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag03[] = {
	sFlag03Pose1,
	sFlag03Pose2,
	sFlag03Pose3,
	sFlag03Pose4,
	sFlag03Pose5,
	sFlag03Pose6,
};

static const ax_anim *const sFlag03AnimTable1[] = {
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
	sFlag03Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag03[] = {
	sFlag03AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag03[] = {
	sFlag03Sprites1,
	sFlag03Sprites2,
	sFlag03Sprites3,
	sFlag03Sprites4,
	sFlag03Sprites5,
	sFlag03Sprites6,
};

static const axmain sAxMainFlag03 = {
	.poses = sAxPosesFlag03,
	.animations = sAxAnimationsFlag03,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag03),
	.spriteData = sAxSpritesFlag03,
	.positions = NULL,
};
const RGB gFlag04Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag04.pmdpal") };

static const axmain sAxMainFlag04;
const SiroArchive gAxFlag04 = {"SIRO", &sAxMainFlag04};

static const ax_pose sFlag04Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag04Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag04Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag04Gfx1[] = INCBIN_U8("graphics/ornament/Flag04/sprite_1.4bpp");
static const ax_sprite sFlag04Sprites1[] = {
	{sFlag04Gfx1, ARRAY_COUNT(sFlag04Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx2[] = INCBIN_U8("graphics/ornament/Flag04/sprite_2.4bpp");
static const ax_sprite sFlag04Sprites2[] = {
	{sFlag04Gfx2, ARRAY_COUNT(sFlag04Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx3[] = INCBIN_U8("graphics/ornament/Flag04/sprite_3.4bpp");
static const ax_sprite sFlag04Sprites3[] = {
	{sFlag04Gfx3, ARRAY_COUNT(sFlag04Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx4[] = INCBIN_U8("graphics/ornament/Flag04/sprite_4.4bpp");
static const ax_sprite sFlag04Sprites4[] = {
	{sFlag04Gfx4, ARRAY_COUNT(sFlag04Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx5[] = INCBIN_U8("graphics/ornament/Flag04/sprite_5.4bpp");
static const ax_sprite sFlag04Sprites5[] = {
	{sFlag04Gfx5, ARRAY_COUNT(sFlag04Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag04Gfx6[] = INCBIN_U8("graphics/ornament/Flag04/sprite_6.4bpp");
static const ax_sprite sFlag04Sprites6[] = {
	{sFlag04Gfx6, ARRAY_COUNT(sFlag04Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag04[] = {
	sFlag04Pose1,
	sFlag04Pose2,
	sFlag04Pose3,
	sFlag04Pose4,
	sFlag04Pose5,
	sFlag04Pose6,
};

static const ax_anim *const sFlag04AnimTable1[] = {
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
	sFlag04Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag04[] = {
	sFlag04AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag04[] = {
	sFlag04Sprites1,
	sFlag04Sprites2,
	sFlag04Sprites3,
	sFlag04Sprites4,
	sFlag04Sprites5,
	sFlag04Sprites6,
};

static const axmain sAxMainFlag04 = {
	.poses = sAxPosesFlag04,
	.animations = sAxAnimationsFlag04,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag04),
	.spriteData = sAxSpritesFlag04,
	.positions = NULL,
};
const RGB gFlag05Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag05.pmdpal") };

static const axmain sAxMainFlag05;
const SiroArchive gAxFlag05 = {"SIRO", &sAxMainFlag05};

static const ax_pose sFlag05Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag05Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag05Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag05Gfx1[] = INCBIN_U8("graphics/ornament/Flag05/sprite_1.4bpp");
static const ax_sprite sFlag05Sprites1[] = {
	{sFlag05Gfx1, ARRAY_COUNT(sFlag05Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx2[] = INCBIN_U8("graphics/ornament/Flag05/sprite_2.4bpp");
static const ax_sprite sFlag05Sprites2[] = {
	{sFlag05Gfx2, ARRAY_COUNT(sFlag05Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx3[] = INCBIN_U8("graphics/ornament/Flag05/sprite_3.4bpp");
static const ax_sprite sFlag05Sprites3[] = {
	{sFlag05Gfx3, ARRAY_COUNT(sFlag05Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx4[] = INCBIN_U8("graphics/ornament/Flag05/sprite_4.4bpp");
static const ax_sprite sFlag05Sprites4[] = {
	{sFlag05Gfx4, ARRAY_COUNT(sFlag05Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx5[] = INCBIN_U8("graphics/ornament/Flag05/sprite_5.4bpp");
static const ax_sprite sFlag05Sprites5[] = {
	{sFlag05Gfx5, ARRAY_COUNT(sFlag05Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag05Gfx6[] = INCBIN_U8("graphics/ornament/Flag05/sprite_6.4bpp");
static const ax_sprite sFlag05Sprites6[] = {
	{sFlag05Gfx6, ARRAY_COUNT(sFlag05Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag05[] = {
	sFlag05Pose1,
	sFlag05Pose2,
	sFlag05Pose3,
	sFlag05Pose4,
	sFlag05Pose5,
	sFlag05Pose6,
};

static const ax_anim *const sFlag05AnimTable1[] = {
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
	sFlag05Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag05[] = {
	sFlag05AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag05[] = {
	sFlag05Sprites1,
	sFlag05Sprites2,
	sFlag05Sprites3,
	sFlag05Sprites4,
	sFlag05Sprites5,
	sFlag05Sprites6,
};

static const axmain sAxMainFlag05 = {
	.poses = sAxPosesFlag05,
	.animations = sAxAnimationsFlag05,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag05),
	.spriteData = sAxSpritesFlag05,
	.positions = NULL,
};
const RGB gFlag06Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag06.pmdpal") };

static const axmain sAxMainFlag06;
const SiroArchive gAxFlag06 = {"SIRO", &sAxMainFlag06};

static const ax_pose sFlag06Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag06Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag06Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag06Gfx1[] = INCBIN_U8("graphics/ornament/Flag06/sprite_1.4bpp");
static const ax_sprite sFlag06Sprites1[] = {
	{sFlag06Gfx1, ARRAY_COUNT(sFlag06Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx2[] = INCBIN_U8("graphics/ornament/Flag06/sprite_2.4bpp");
static const ax_sprite sFlag06Sprites2[] = {
	{sFlag06Gfx2, ARRAY_COUNT(sFlag06Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx3[] = INCBIN_U8("graphics/ornament/Flag06/sprite_3.4bpp");
static const ax_sprite sFlag06Sprites3[] = {
	{sFlag06Gfx3, ARRAY_COUNT(sFlag06Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx4[] = INCBIN_U8("graphics/ornament/Flag06/sprite_4.4bpp");
static const ax_sprite sFlag06Sprites4[] = {
	{sFlag06Gfx4, ARRAY_COUNT(sFlag06Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx5[] = INCBIN_U8("graphics/ornament/Flag06/sprite_5.4bpp");
static const ax_sprite sFlag06Sprites5[] = {
	{sFlag06Gfx5, ARRAY_COUNT(sFlag06Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag06Gfx6[] = INCBIN_U8("graphics/ornament/Flag06/sprite_6.4bpp");
static const ax_sprite sFlag06Sprites6[] = {
	{sFlag06Gfx6, ARRAY_COUNT(sFlag06Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag06[] = {
	sFlag06Pose1,
	sFlag06Pose2,
	sFlag06Pose3,
	sFlag06Pose4,
	sFlag06Pose5,
	sFlag06Pose6,
};

static const ax_anim *const sFlag06AnimTable1[] = {
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
	sFlag06Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag06[] = {
	sFlag06AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag06[] = {
	sFlag06Sprites1,
	sFlag06Sprites2,
	sFlag06Sprites3,
	sFlag06Sprites4,
	sFlag06Sprites5,
	sFlag06Sprites6,
};

static const axmain sAxMainFlag06 = {
	.poses = sAxPosesFlag06,
	.animations = sAxAnimationsFlag06,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag06),
	.spriteData = sAxSpritesFlag06,
	.positions = NULL,
};
const RGB gFlag07Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag07.pmdpal") };

static const axmain sAxMainFlag07;
const SiroArchive gAxFlag07 = {"SIRO", &sAxMainFlag07};

static const ax_pose sFlag07Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag07Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag07Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag07Gfx1[] = INCBIN_U8("graphics/ornament/Flag07/sprite_1.4bpp");
static const ax_sprite sFlag07Sprites1[] = {
	{sFlag07Gfx1, ARRAY_COUNT(sFlag07Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx2[] = INCBIN_U8("graphics/ornament/Flag07/sprite_2.4bpp");
static const ax_sprite sFlag07Sprites2[] = {
	{sFlag07Gfx2, ARRAY_COUNT(sFlag07Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx3[] = INCBIN_U8("graphics/ornament/Flag07/sprite_3.4bpp");
static const ax_sprite sFlag07Sprites3[] = {
	{sFlag07Gfx3, ARRAY_COUNT(sFlag07Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx4[] = INCBIN_U8("graphics/ornament/Flag07/sprite_4.4bpp");
static const ax_sprite sFlag07Sprites4[] = {
	{sFlag07Gfx4, ARRAY_COUNT(sFlag07Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx5[] = INCBIN_U8("graphics/ornament/Flag07/sprite_5.4bpp");
static const ax_sprite sFlag07Sprites5[] = {
	{sFlag07Gfx5, ARRAY_COUNT(sFlag07Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag07Gfx6[] = INCBIN_U8("graphics/ornament/Flag07/sprite_6.4bpp");
static const ax_sprite sFlag07Sprites6[] = {
	{sFlag07Gfx6, ARRAY_COUNT(sFlag07Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag07[] = {
	sFlag07Pose1,
	sFlag07Pose2,
	sFlag07Pose3,
	sFlag07Pose4,
	sFlag07Pose5,
	sFlag07Pose6,
};

static const ax_anim *const sFlag07AnimTable1[] = {
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
	sFlag07Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag07[] = {
	sFlag07AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag07[] = {
	sFlag07Sprites1,
	sFlag07Sprites2,
	sFlag07Sprites3,
	sFlag07Sprites4,
	sFlag07Sprites5,
	sFlag07Sprites6,
};

static const axmain sAxMainFlag07 = {
	.poses = sAxPosesFlag07,
	.animations = sAxAnimationsFlag07,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag07),
	.spriteData = sAxSpritesFlag07,
	.positions = NULL,
};
