#include "global.h"
#include "globaldata.h"
#include "ornament_gfx.h"

const RGB gFlag08Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag08.pmdpal") };

static const axmain sAxMainFlag08;
const SiroArchive gAxFlag08 = {"SIRO", &sAxMainFlag08};

static const ax_pose sFlag08Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag08Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag08Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag08Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag08Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag08Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag08Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag08Gfx1[] = INCBIN_U8("graphics/ornament/Flag08/sprite_1.4bpp");
static const ax_sprite sFlag08Sprites1[] = {
	{sFlag08Gfx1, ARRAY_COUNT(sFlag08Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag08Gfx2[] = INCBIN_U8("graphics/ornament/Flag08/sprite_2.4bpp");
static const ax_sprite sFlag08Sprites2[] = {
	{sFlag08Gfx2, ARRAY_COUNT(sFlag08Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag08Gfx3[] = INCBIN_U8("graphics/ornament/Flag08/sprite_3.4bpp");
static const ax_sprite sFlag08Sprites3[] = {
	{sFlag08Gfx3, ARRAY_COUNT(sFlag08Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag08Gfx4[] = INCBIN_U8("graphics/ornament/Flag08/sprite_4.4bpp");
static const ax_sprite sFlag08Sprites4[] = {
	{sFlag08Gfx4, ARRAY_COUNT(sFlag08Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag08Gfx5[] = INCBIN_U8("graphics/ornament/Flag08/sprite_5.4bpp");
static const ax_sprite sFlag08Sprites5[] = {
	{sFlag08Gfx5, ARRAY_COUNT(sFlag08Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag08Gfx6[] = INCBIN_U8("graphics/ornament/Flag08/sprite_6.4bpp");
static const ax_sprite sFlag08Sprites6[] = {
	{sFlag08Gfx6, ARRAY_COUNT(sFlag08Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag08[] = {
	sFlag08Pose1,
	sFlag08Pose2,
	sFlag08Pose3,
	sFlag08Pose4,
	sFlag08Pose5,
	sFlag08Pose6,
};

static const ax_anim *const sFlag08AnimTable1[] = {
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
	sFlag08Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag08[] = {
	sFlag08AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag08[] = {
	sFlag08Sprites1,
	sFlag08Sprites2,
	sFlag08Sprites3,
	sFlag08Sprites4,
	sFlag08Sprites5,
	sFlag08Sprites6,
};

static const axmain sAxMainFlag08 = {
	.poses = sAxPosesFlag08,
	.animations = sAxAnimationsFlag08,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag08),
	.spriteData = sAxSpritesFlag08,
	.positions = NULL,
};
const RGB gFlag09Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag09.pmdpal") };

static const axmain sAxMainFlag09;
const SiroArchive gAxFlag09 = {"SIRO", &sAxMainFlag09};

static const ax_pose sFlag09Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag09Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag09Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag09Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag09Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag09Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag09Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag09Gfx1[] = INCBIN_U8("graphics/ornament/Flag09/sprite_1.4bpp");
static const ax_sprite sFlag09Sprites1[] = {
	{sFlag09Gfx1, ARRAY_COUNT(sFlag09Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag09Gfx2[] = INCBIN_U8("graphics/ornament/Flag09/sprite_2.4bpp");
static const ax_sprite sFlag09Sprites2[] = {
	{sFlag09Gfx2, ARRAY_COUNT(sFlag09Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag09Gfx3[] = INCBIN_U8("graphics/ornament/Flag09/sprite_3.4bpp");
static const ax_sprite sFlag09Sprites3[] = {
	{sFlag09Gfx3, ARRAY_COUNT(sFlag09Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag09Gfx4[] = INCBIN_U8("graphics/ornament/Flag09/sprite_4.4bpp");
static const ax_sprite sFlag09Sprites4[] = {
	{sFlag09Gfx4, ARRAY_COUNT(sFlag09Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag09Gfx5[] = INCBIN_U8("graphics/ornament/Flag09/sprite_5.4bpp");
static const ax_sprite sFlag09Sprites5[] = {
	{sFlag09Gfx5, ARRAY_COUNT(sFlag09Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag09Gfx6[] = INCBIN_U8("graphics/ornament/Flag09/sprite_6.4bpp");
static const ax_sprite sFlag09Sprites6[] = {
	{sFlag09Gfx6, ARRAY_COUNT(sFlag09Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag09[] = {
	sFlag09Pose1,
	sFlag09Pose2,
	sFlag09Pose3,
	sFlag09Pose4,
	sFlag09Pose5,
	sFlag09Pose6,
};

static const ax_anim *const sFlag09AnimTable1[] = {
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
	sFlag09Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag09[] = {
	sFlag09AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag09[] = {
	sFlag09Sprites1,
	sFlag09Sprites2,
	sFlag09Sprites3,
	sFlag09Sprites4,
	sFlag09Sprites5,
	sFlag09Sprites6,
};

static const axmain sAxMainFlag09 = {
	.poses = sAxPosesFlag09,
	.animations = sAxAnimationsFlag09,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag09),
	.spriteData = sAxSpritesFlag09,
	.positions = NULL,
};
const RGB gFlag100Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag100.pmdpal") };

static const axmain sAxMainFlag100;
const SiroArchive gAxFlag100 = {"SIRO", &sAxMainFlag100};

static const ax_pose sFlag100Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag100Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag100Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag100Gfx1[] = INCBIN_U8("graphics/ornament/Flag100/sprite_1.4bpp");
static const ax_sprite sFlag100Sprites1[] = {
	{sFlag100Gfx1, ARRAY_COUNT(sFlag100Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx2[] = INCBIN_U8("graphics/ornament/Flag100/sprite_2.4bpp");
static const ax_sprite sFlag100Sprites2[] = {
	{sFlag100Gfx2, ARRAY_COUNT(sFlag100Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx3[] = INCBIN_U8("graphics/ornament/Flag100/sprite_3.4bpp");
static const ax_sprite sFlag100Sprites3[] = {
	{sFlag100Gfx3, ARRAY_COUNT(sFlag100Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx4[] = INCBIN_U8("graphics/ornament/Flag100/sprite_4.4bpp");
static const ax_sprite sFlag100Sprites4[] = {
	{sFlag100Gfx4, ARRAY_COUNT(sFlag100Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx5[] = INCBIN_U8("graphics/ornament/Flag100/sprite_5.4bpp");
static const ax_sprite sFlag100Sprites5[] = {
	{sFlag100Gfx5, ARRAY_COUNT(sFlag100Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag100Gfx6[] = INCBIN_U8("graphics/ornament/Flag100/sprite_6.4bpp");
static const ax_sprite sFlag100Sprites6[] = {
	{sFlag100Gfx6, ARRAY_COUNT(sFlag100Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag100[] = {
	sFlag100Pose1,
	sFlag100Pose2,
	sFlag100Pose3,
	sFlag100Pose4,
	sFlag100Pose5,
	sFlag100Pose6,
};

static const ax_anim *const sFlag100AnimTable1[] = {
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
	sFlag100Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag100[] = {
	sFlag100AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag100[] = {
	sFlag100Sprites1,
	sFlag100Sprites2,
	sFlag100Sprites3,
	sFlag100Sprites4,
	sFlag100Sprites5,
	sFlag100Sprites6,
};

static const axmain sAxMainFlag100 = {
	.poses = sAxPosesFlag100,
	.animations = sAxAnimationsFlag100,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag100),
	.spriteData = sAxSpritesFlag100,
	.positions = NULL,
};
const RGB gFlag101Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag101.pmdpal") };

static const axmain sAxMainFlag101;
const SiroArchive gAxFlag101 = {"SIRO", &sAxMainFlag101};

static const ax_pose sFlag101Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag101Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag101Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag101Gfx1[] = INCBIN_U8("graphics/ornament/Flag101/sprite_1.4bpp");
static const ax_sprite sFlag101Sprites1[] = {
	{sFlag101Gfx1, ARRAY_COUNT(sFlag101Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx2[] = INCBIN_U8("graphics/ornament/Flag101/sprite_2.4bpp");
static const ax_sprite sFlag101Sprites2[] = {
	{sFlag101Gfx2, ARRAY_COUNT(sFlag101Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx3[] = INCBIN_U8("graphics/ornament/Flag101/sprite_3.4bpp");
static const ax_sprite sFlag101Sprites3[] = {
	{sFlag101Gfx3, ARRAY_COUNT(sFlag101Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx4[] = INCBIN_U8("graphics/ornament/Flag101/sprite_4.4bpp");
static const ax_sprite sFlag101Sprites4[] = {
	{sFlag101Gfx4, ARRAY_COUNT(sFlag101Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx5[] = INCBIN_U8("graphics/ornament/Flag101/sprite_5.4bpp");
static const ax_sprite sFlag101Sprites5[] = {
	{sFlag101Gfx5, ARRAY_COUNT(sFlag101Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag101Gfx6[] = INCBIN_U8("graphics/ornament/Flag101/sprite_6.4bpp");
static const ax_sprite sFlag101Sprites6[] = {
	{sFlag101Gfx6, ARRAY_COUNT(sFlag101Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag101[] = {
	sFlag101Pose1,
	sFlag101Pose2,
	sFlag101Pose3,
	sFlag101Pose4,
	sFlag101Pose5,
	sFlag101Pose6,
};

static const ax_anim *const sFlag101AnimTable1[] = {
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
	sFlag101Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag101[] = {
	sFlag101AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag101[] = {
	sFlag101Sprites1,
	sFlag101Sprites2,
	sFlag101Sprites3,
	sFlag101Sprites4,
	sFlag101Sprites5,
	sFlag101Sprites6,
};

static const axmain sAxMainFlag101 = {
	.poses = sAxPosesFlag101,
	.animations = sAxAnimationsFlag101,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag101),
	.spriteData = sAxSpritesFlag101,
	.positions = NULL,
};
const RGB gFlag102Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag102.pmdpal") };

static const axmain sAxMainFlag102;
const SiroArchive gAxFlag102 = {"SIRO", &sAxMainFlag102};

static const ax_pose sFlag102Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag102Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag102Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag102Gfx1[] = INCBIN_U8("graphics/ornament/Flag102/sprite_1.4bpp");
static const ax_sprite sFlag102Sprites1[] = {
	{sFlag102Gfx1, ARRAY_COUNT(sFlag102Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx2[] = INCBIN_U8("graphics/ornament/Flag102/sprite_2.4bpp");
static const ax_sprite sFlag102Sprites2[] = {
	{sFlag102Gfx2, ARRAY_COUNT(sFlag102Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx3[] = INCBIN_U8("graphics/ornament/Flag102/sprite_3.4bpp");
static const ax_sprite sFlag102Sprites3[] = {
	{sFlag102Gfx3, ARRAY_COUNT(sFlag102Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx4[] = INCBIN_U8("graphics/ornament/Flag102/sprite_4.4bpp");
static const ax_sprite sFlag102Sprites4[] = {
	{sFlag102Gfx4, ARRAY_COUNT(sFlag102Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx5[] = INCBIN_U8("graphics/ornament/Flag102/sprite_5.4bpp");
static const ax_sprite sFlag102Sprites5[] = {
	{sFlag102Gfx5, ARRAY_COUNT(sFlag102Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag102Gfx6[] = INCBIN_U8("graphics/ornament/Flag102/sprite_6.4bpp");
static const ax_sprite sFlag102Sprites6[] = {
	{sFlag102Gfx6, ARRAY_COUNT(sFlag102Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag102[] = {
	sFlag102Pose1,
	sFlag102Pose2,
	sFlag102Pose3,
	sFlag102Pose4,
	sFlag102Pose5,
	sFlag102Pose6,
};

static const ax_anim *const sFlag102AnimTable1[] = {
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
	sFlag102Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag102[] = {
	sFlag102AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag102[] = {
	sFlag102Sprites1,
	sFlag102Sprites2,
	sFlag102Sprites3,
	sFlag102Sprites4,
	sFlag102Sprites5,
	sFlag102Sprites6,
};

static const axmain sAxMainFlag102 = {
	.poses = sAxPosesFlag102,
	.animations = sAxAnimationsFlag102,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag102),
	.spriteData = sAxSpritesFlag102,
	.positions = NULL,
};
const RGB gFlag103Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag103.pmdpal") };

static const axmain sAxMainFlag103;
const SiroArchive gAxFlag103 = {"SIRO", &sAxMainFlag103};

static const ax_pose sFlag103Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag103Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag103Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag103Gfx1[] = INCBIN_U8("graphics/ornament/Flag103/sprite_1.4bpp");
static const ax_sprite sFlag103Sprites1[] = {
	{sFlag103Gfx1, ARRAY_COUNT(sFlag103Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx2[] = INCBIN_U8("graphics/ornament/Flag103/sprite_2.4bpp");
static const ax_sprite sFlag103Sprites2[] = {
	{sFlag103Gfx2, ARRAY_COUNT(sFlag103Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx3[] = INCBIN_U8("graphics/ornament/Flag103/sprite_3.4bpp");
static const ax_sprite sFlag103Sprites3[] = {
	{sFlag103Gfx3, ARRAY_COUNT(sFlag103Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx4[] = INCBIN_U8("graphics/ornament/Flag103/sprite_4.4bpp");
static const ax_sprite sFlag103Sprites4[] = {
	{sFlag103Gfx4, ARRAY_COUNT(sFlag103Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx5[] = INCBIN_U8("graphics/ornament/Flag103/sprite_5.4bpp");
static const ax_sprite sFlag103Sprites5[] = {
	{sFlag103Gfx5, ARRAY_COUNT(sFlag103Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag103Gfx6[] = INCBIN_U8("graphics/ornament/Flag103/sprite_6.4bpp");
static const ax_sprite sFlag103Sprites6[] = {
	{sFlag103Gfx6, ARRAY_COUNT(sFlag103Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag103[] = {
	sFlag103Pose1,
	sFlag103Pose2,
	sFlag103Pose3,
	sFlag103Pose4,
	sFlag103Pose5,
	sFlag103Pose6,
};

static const ax_anim *const sFlag103AnimTable1[] = {
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
	sFlag103Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag103[] = {
	sFlag103AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag103[] = {
	sFlag103Sprites1,
	sFlag103Sprites2,
	sFlag103Sprites3,
	sFlag103Sprites4,
	sFlag103Sprites5,
	sFlag103Sprites6,
};

static const axmain sAxMainFlag103 = {
	.poses = sAxPosesFlag103,
	.animations = sAxAnimationsFlag103,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag103),
	.spriteData = sAxSpritesFlag103,
	.positions = NULL,
};
const RGB gFlag104Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag104.pmdpal") };

static const axmain sAxMainFlag104;
const SiroArchive gAxFlag104 = {"SIRO", &sAxMainFlag104};

static const ax_pose sFlag104Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag104Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag104Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag104Gfx1[] = INCBIN_U8("graphics/ornament/Flag104/sprite_1.4bpp");
static const ax_sprite sFlag104Sprites1[] = {
	{sFlag104Gfx1, ARRAY_COUNT(sFlag104Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx2[] = INCBIN_U8("graphics/ornament/Flag104/sprite_2.4bpp");
static const ax_sprite sFlag104Sprites2[] = {
	{sFlag104Gfx2, ARRAY_COUNT(sFlag104Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx3[] = INCBIN_U8("graphics/ornament/Flag104/sprite_3.4bpp");
static const ax_sprite sFlag104Sprites3[] = {
	{sFlag104Gfx3, ARRAY_COUNT(sFlag104Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx4[] = INCBIN_U8("graphics/ornament/Flag104/sprite_4.4bpp");
static const ax_sprite sFlag104Sprites4[] = {
	{sFlag104Gfx4, ARRAY_COUNT(sFlag104Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx5[] = INCBIN_U8("graphics/ornament/Flag104/sprite_5.4bpp");
static const ax_sprite sFlag104Sprites5[] = {
	{sFlag104Gfx5, ARRAY_COUNT(sFlag104Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag104Gfx6[] = INCBIN_U8("graphics/ornament/Flag104/sprite_6.4bpp");
static const ax_sprite sFlag104Sprites6[] = {
	{sFlag104Gfx6, ARRAY_COUNT(sFlag104Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag104[] = {
	sFlag104Pose1,
	sFlag104Pose2,
	sFlag104Pose3,
	sFlag104Pose4,
	sFlag104Pose5,
	sFlag104Pose6,
};

static const ax_anim *const sFlag104AnimTable1[] = {
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
	sFlag104Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag104[] = {
	sFlag104AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag104[] = {
	sFlag104Sprites1,
	sFlag104Sprites2,
	sFlag104Sprites3,
	sFlag104Sprites4,
	sFlag104Sprites5,
	sFlag104Sprites6,
};

static const axmain sAxMainFlag104 = {
	.poses = sAxPosesFlag104,
	.animations = sAxAnimationsFlag104,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag104),
	.spriteData = sAxSpritesFlag104,
	.positions = NULL,
};
const RGB gFlag105Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag105.pmdpal") };

static const axmain sAxMainFlag105;
const SiroArchive gAxFlag105 = {"SIRO", &sAxMainFlag105};

static const ax_pose sFlag105Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag105Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag105Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag105Gfx1[] = INCBIN_U8("graphics/ornament/Flag105/sprite_1.4bpp");
static const ax_sprite sFlag105Sprites1[] = {
	{sFlag105Gfx1, ARRAY_COUNT(sFlag105Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx2[] = INCBIN_U8("graphics/ornament/Flag105/sprite_2.4bpp");
static const ax_sprite sFlag105Sprites2[] = {
	{sFlag105Gfx2, ARRAY_COUNT(sFlag105Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx3[] = INCBIN_U8("graphics/ornament/Flag105/sprite_3.4bpp");
static const ax_sprite sFlag105Sprites3[] = {
	{sFlag105Gfx3, ARRAY_COUNT(sFlag105Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx4[] = INCBIN_U8("graphics/ornament/Flag105/sprite_4.4bpp");
static const ax_sprite sFlag105Sprites4[] = {
	{sFlag105Gfx4, ARRAY_COUNT(sFlag105Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx5[] = INCBIN_U8("graphics/ornament/Flag105/sprite_5.4bpp");
static const ax_sprite sFlag105Sprites5[] = {
	{sFlag105Gfx5, ARRAY_COUNT(sFlag105Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag105Gfx6[] = INCBIN_U8("graphics/ornament/Flag105/sprite_6.4bpp");
static const ax_sprite sFlag105Sprites6[] = {
	{sFlag105Gfx6, ARRAY_COUNT(sFlag105Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag105[] = {
	sFlag105Pose1,
	sFlag105Pose2,
	sFlag105Pose3,
	sFlag105Pose4,
	sFlag105Pose5,
	sFlag105Pose6,
};

static const ax_anim *const sFlag105AnimTable1[] = {
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
	sFlag105Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag105[] = {
	sFlag105AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag105[] = {
	sFlag105Sprites1,
	sFlag105Sprites2,
	sFlag105Sprites3,
	sFlag105Sprites4,
	sFlag105Sprites5,
	sFlag105Sprites6,
};

static const axmain sAxMainFlag105 = {
	.poses = sAxPosesFlag105,
	.animations = sAxAnimationsFlag105,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag105),
	.spriteData = sAxSpritesFlag105,
	.positions = NULL,
};
