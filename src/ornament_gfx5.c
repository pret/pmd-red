#include "global.h"
#include "globaldata.h"
#include "ornament_gfx.h"

static const axmain sAxMainItem01;
const SiroArchive gAxItem01 = {"SIRO", &sAxMainItem01};

static const ax_pose sItem01Pose1[] = {
	AX_POSE(0, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose2[] = {
	AX_POSE(1, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose3[] = {
	AX_POSE(2, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 7)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose4[] = {
	AX_POSE(3, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 3)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose5[] = {
	AX_POSE(4, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 12)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose6[] = {
	AX_POSE(5, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose7[] = {
	AX_POSE(6, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 12)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose8[] = {
	AX_POSE(7, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose9[] = {
	AX_POSE(8, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose10[] = {
	AX_POSE(9, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 2)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose11[] = {
	AX_POSE(10, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose12[] = {
	AX_POSE(11, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose13[] = {
	AX_POSE(12, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose14[] = {
	AX_POSE(13, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose15[] = {
	AX_POSE(14, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 8)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose16[] = {
	AX_POSE(15, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose17[] = {
	AX_POSE(16, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 12)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose18[] = {
	AX_POSE(17, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose19[] = {
	AX_POSE(18, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose20[] = {
	AX_POSE(19, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 4)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose21[] = {
	AX_POSE(20, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose22[] = {
	AX_POSE(21, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose23[] = {
	AX_POSE(22, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_pose sItem01Pose24[] = {
	AX_POSE(23, OAM1(248, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_1, FLIP(0, 0), 2, 0), OAM3(0, 3, 10)),
	AX_POSE_TERMINATOR
};
static const ax_anim sItem01Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_2[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_3[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 11, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_4[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 17, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_5[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_6[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_7[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sItem01Anims_1_8[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 19, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sItem01Gfx1[] = INCBIN_U8("graphics/ornament/Item01/sprite_1.4bpp");
static const ax_sprite sItem01Sprites1[] = {
	{sItem01Gfx1, ARRAY_COUNT(sItem01Gfx1)},
	{NULL, 0},
};
static const u8 sItem01Gfx2[] = INCBIN_U8("graphics/ornament/Item01/sprite_2.4bpp");
static const ax_sprite sItem01Sprites2[] = {
	{sItem01Gfx2, ARRAY_COUNT(sItem01Gfx2)},
	{NULL, 0},
};
static const u8 sItem01Gfx3[] = INCBIN_U8("graphics/ornament/Item01/sprite_3.4bpp");
static const ax_sprite sItem01Sprites3[] = {
	{sItem01Gfx3, ARRAY_COUNT(sItem01Gfx3)},
	{NULL, 0},
};
static const u8 sItem01Gfx4[] = INCBIN_U8("graphics/ornament/Item01/sprite_4.4bpp");
static const ax_sprite sItem01Sprites4[] = {
	{sItem01Gfx4, ARRAY_COUNT(sItem01Gfx4)},
	{NULL, 0},
};
static const u8 sItem01Gfx5[] = INCBIN_U8("graphics/ornament/Item01/sprite_5.4bpp");
static const ax_sprite sItem01Sprites5[] = {
	{sItem01Gfx5, ARRAY_COUNT(sItem01Gfx5)},
	{NULL, 0},
};
static const u8 sItem01Gfx6[] = INCBIN_U8("graphics/ornament/Item01/sprite_6.4bpp");
static const ax_sprite sItem01Sprites6[] = {
	{sItem01Gfx6, ARRAY_COUNT(sItem01Gfx6)},
	{NULL, 0},
};
static const u8 sItem01Gfx7[] = INCBIN_U8("graphics/ornament/Item01/sprite_7.4bpp");
static const ax_sprite sItem01Sprites7[] = {
	{sItem01Gfx7, ARRAY_COUNT(sItem01Gfx7)},
	{NULL, 0},
};
static const u8 sItem01Gfx8[] = INCBIN_U8("graphics/ornament/Item01/sprite_8.4bpp");
static const ax_sprite sItem01Sprites8[] = {
	{sItem01Gfx8, ARRAY_COUNT(sItem01Gfx8)},
	{NULL, 0},
};
static const u8 sItem01Gfx9[] = INCBIN_U8("graphics/ornament/Item01/sprite_9.4bpp");
static const ax_sprite sItem01Sprites9[] = {
	{sItem01Gfx9, ARRAY_COUNT(sItem01Gfx9)},
	{NULL, 0},
};
static const u8 sItem01Gfx10[] = INCBIN_U8("graphics/ornament/Item01/sprite_10.4bpp");
static const ax_sprite sItem01Sprites10[] = {
	{sItem01Gfx10, ARRAY_COUNT(sItem01Gfx10)},
	{NULL, 0},
};
static const u8 sItem01Gfx11[] = INCBIN_U8("graphics/ornament/Item01/sprite_11.4bpp");
static const ax_sprite sItem01Sprites11[] = {
	{sItem01Gfx11, ARRAY_COUNT(sItem01Gfx11)},
	{NULL, 0},
};
static const u8 sItem01Gfx12[] = INCBIN_U8("graphics/ornament/Item01/sprite_12.4bpp");
static const ax_sprite sItem01Sprites12[] = {
	{sItem01Gfx12, ARRAY_COUNT(sItem01Gfx12)},
	{NULL, 0},
};
static const u8 sItem01Gfx13[] = INCBIN_U8("graphics/ornament/Item01/sprite_13.4bpp");
static const ax_sprite sItem01Sprites13[] = {
	{sItem01Gfx13, ARRAY_COUNT(sItem01Gfx13)},
	{NULL, 0},
};
static const u8 sItem01Gfx14[] = INCBIN_U8("graphics/ornament/Item01/sprite_14.4bpp");
static const ax_sprite sItem01Sprites14[] = {
	{sItem01Gfx14, ARRAY_COUNT(sItem01Gfx14)},
	{NULL, 0},
};
static const u8 sItem01Gfx15[] = INCBIN_U8("graphics/ornament/Item01/sprite_15.4bpp");
static const ax_sprite sItem01Sprites15[] = {
	{sItem01Gfx15, ARRAY_COUNT(sItem01Gfx15)},
	{NULL, 0},
};
static const u8 sItem01Gfx16[] = INCBIN_U8("graphics/ornament/Item01/sprite_16.4bpp");
static const ax_sprite sItem01Sprites16[] = {
	{sItem01Gfx16, ARRAY_COUNT(sItem01Gfx16)},
	{NULL, 0},
};
static const u8 sItem01Gfx17[] = INCBIN_U8("graphics/ornament/Item01/sprite_17.4bpp");
static const ax_sprite sItem01Sprites17[] = {
	{sItem01Gfx17, ARRAY_COUNT(sItem01Gfx17)},
	{NULL, 0},
};
static const u8 sItem01Gfx18[] = INCBIN_U8("graphics/ornament/Item01/sprite_18.4bpp");
static const ax_sprite sItem01Sprites18[] = {
	{sItem01Gfx18, ARRAY_COUNT(sItem01Gfx18)},
	{NULL, 0},
};
static const u8 sItem01Gfx19[] = INCBIN_U8("graphics/ornament/Item01/sprite_19.4bpp");
static const ax_sprite sItem01Sprites19[] = {
	{sItem01Gfx19, ARRAY_COUNT(sItem01Gfx19)},
	{NULL, 0},
};
static const u8 sItem01Gfx20[] = INCBIN_U8("graphics/ornament/Item01/sprite_20.4bpp");
static const ax_sprite sItem01Sprites20[] = {
	{sItem01Gfx20, ARRAY_COUNT(sItem01Gfx20)},
	{NULL, 0},
};
static const u8 sItem01Gfx21[] = INCBIN_U8("graphics/ornament/Item01/sprite_21.4bpp");
static const ax_sprite sItem01Sprites21[] = {
	{sItem01Gfx21, ARRAY_COUNT(sItem01Gfx21)},
	{NULL, 0},
};
static const u8 sItem01Gfx22[] = INCBIN_U8("graphics/ornament/Item01/sprite_22.4bpp");
static const ax_sprite sItem01Sprites22[] = {
	{sItem01Gfx22, ARRAY_COUNT(sItem01Gfx22)},
	{NULL, 0},
};
static const u8 sItem01Gfx23[] = INCBIN_U8("graphics/ornament/Item01/sprite_23.4bpp");
static const ax_sprite sItem01Sprites23[] = {
	{sItem01Gfx23, ARRAY_COUNT(sItem01Gfx23)},
	{NULL, 0},
};
static const u8 sItem01Gfx24[] = INCBIN_U8("graphics/ornament/Item01/sprite_24.4bpp");
static const ax_sprite sItem01Sprites24[] = {
	{sItem01Gfx24, ARRAY_COUNT(sItem01Gfx24)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesItem01[] = {
	sItem01Pose1,
	sItem01Pose2,
	sItem01Pose3,
	sItem01Pose4,
	sItem01Pose5,
	sItem01Pose6,
	sItem01Pose7,
	sItem01Pose8,
	sItem01Pose9,
	sItem01Pose10,
	sItem01Pose11,
	sItem01Pose12,
	sItem01Pose13,
	sItem01Pose14,
	sItem01Pose15,
	sItem01Pose16,
	sItem01Pose17,
	sItem01Pose18,
	sItem01Pose19,
	sItem01Pose20,
	sItem01Pose21,
	sItem01Pose22,
	sItem01Pose23,
	sItem01Pose24,
};

static const ax_anim *const sItem01AnimTable1[] = {
	sItem01Anims_1_1,
	sItem01Anims_1_2,
	sItem01Anims_1_3,
	sItem01Anims_1_4,
	sItem01Anims_1_5,
	sItem01Anims_1_6,
	sItem01Anims_1_7,
	sItem01Anims_1_8,
};

static const ax_anim *const *const sAxAnimationsItem01[] = {
	sItem01AnimTable1,
};

static const ax_sprite *const sAxSpritesItem01[] = {
	sItem01Sprites1,
	sItem01Sprites2,
	sItem01Sprites3,
	sItem01Sprites4,
	sItem01Sprites5,
	sItem01Sprites6,
	sItem01Sprites7,
	sItem01Sprites8,
	sItem01Sprites9,
	sItem01Sprites10,
	sItem01Sprites11,
	sItem01Sprites12,
	sItem01Sprites13,
	sItem01Sprites14,
	sItem01Sprites15,
	sItem01Sprites16,
	sItem01Sprites17,
	sItem01Sprites18,
	sItem01Sprites19,
	sItem01Sprites20,
	sItem01Sprites21,
	sItem01Sprites22,
	sItem01Sprites23,
	sItem01Sprites24,
};

static const axmain sAxMainItem01 = {
	.poses = sAxPosesItem01,
	.animations = sAxAnimationsItem01,
	.animCount = ARRAY_COUNT(sAxAnimationsItem01),
	.spriteData = sAxSpritesItem01,
	.positions = NULL,
};
static const axmain sAxMainNpc01;
const SiroArchive gAxNpc01 = {"SIRO", &sAxMainNpc01};

static const ax_pose sNpc01Pose1[] = {
	AX_POSE(0, OAM1(229, ST_OAM_SQUARE     , 1), OAM2(243, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc01Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc01Gfx1[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1.4bpp");
static const u8 sNpc01Gfx1_2[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_2.4bpp");
static const u8 sNpc01Gfx1_3[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_3.4bpp");
static const u8 sNpc01Gfx1_4[] = INCBIN_U8("graphics/ornament/Npc01/sprite_1_4.4bpp");
static const ax_sprite sNpc01Sprites1[] = {
	{NULL, 32},
	{sNpc01Gfx1, ARRAY_COUNT(sNpc01Gfx1)},
	{NULL, 64},
	{sNpc01Gfx1_2, ARRAY_COUNT(sNpc01Gfx1_2)},
	{NULL, 32},
	{sNpc01Gfx1_3, ARRAY_COUNT(sNpc01Gfx1_3)},
	{NULL, 32},
	{sNpc01Gfx1_4, ARRAY_COUNT(sNpc01Gfx1_4)},
	{NULL, 32},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc01[] = {
	sNpc01Pose1,
};

static const ax_anim *const sNpc01AnimTable1[] = {
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
	sNpc01Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc01[] = {
	sNpc01AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc01[] = {
	sNpc01Sprites1,
};

static const axmain sAxMainNpc01 = {
	.poses = sAxPosesNpc01,
	.animations = sAxAnimationsNpc01,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc01),
	.spriteData = sAxSpritesNpc01,
	.positions = NULL,
};
static const axmain sAxMainNpc02;
const SiroArchive gAxNpc02 = {"SIRO", &sAxMainNpc02};

static const ax_pose sNpc02Pose1[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(242, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc02Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc02Gfx1[] = INCBIN_U8("graphics/ornament/Npc02/sprite_1.4bpp");
static const ax_sprite sNpc02Sprites1[] = {
	{sNpc02Gfx1, ARRAY_COUNT(sNpc02Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc02[] = {
	sNpc02Pose1,
};

static const ax_anim *const sNpc02AnimTable1[] = {
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
	sNpc02Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc02[] = {
	sNpc02AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc02[] = {
	sNpc02Sprites1,
};

static const axmain sAxMainNpc02 = {
	.poses = sAxPosesNpc02,
	.animations = sAxAnimationsNpc02,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc02),
	.spriteData = sAxSpritesNpc02,
	.positions = NULL,
};
static const axmain sAxMainNpc03;
const SiroArchive gAxNpc03 = {"SIRO", &sAxMainNpc03};

static const ax_pose sNpc03Pose1[] = {
	AX_POSE(0, OAM1(227, ST_OAM_SQUARE     , 1), OAM2(241, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc03Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc03Gfx1[] = INCBIN_U8("graphics/ornament/Npc03/sprite_1.4bpp");
static const ax_sprite sNpc03Sprites1[] = {
	{NULL, 32},
	{sNpc03Gfx1, ARRAY_COUNT(sNpc03Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc03[] = {
	sNpc03Pose1,
};

static const ax_anim *const sNpc03AnimTable1[] = {
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
	sNpc03Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc03[] = {
	sNpc03AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc03[] = {
	sNpc03Sprites1,
};

static const axmain sAxMainNpc03 = {
	.poses = sAxPosesNpc03,
	.animations = sAxAnimationsNpc03,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc03),
	.spriteData = sAxSpritesNpc03,
	.positions = NULL,
};
static const axmain sAxMainNpc04;
const SiroArchive gAxNpc04 = {"SIRO", &sAxMainNpc04};

static const ax_pose sNpc04Pose1[] = {
	AX_POSE(0, OAM1(233, ST_OAM_V_RECTANGLE, 1), OAM2(248, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 6)),
	AX_POSE_TERMINATOR
};
static const ax_anim sNpc04Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sNpc04Gfx1[] = INCBIN_U8("graphics/ornament/Npc04/sprite_1.4bpp");
static const ax_sprite sNpc04Sprites1[] = {
	{sNpc04Gfx1, ARRAY_COUNT(sNpc04Gfx1)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesNpc04[] = {
	sNpc04Pose1,
};

static const ax_anim *const sNpc04AnimTable1[] = {
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
	sNpc04Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsNpc04[] = {
	sNpc04AnimTable1,
};

static const ax_sprite *const sAxSpritesNpc04[] = {
	sNpc04Sprites1,
};

static const axmain sAxMainNpc04 = {
	.poses = sAxPosesNpc04,
	.animations = sAxAnimationsNpc04,
	.animCount = ARRAY_COUNT(sAxAnimationsNpc04),
	.spriteData = sAxSpritesNpc04,
	.positions = NULL,
};
const RGB gStoneimPal[] = { INCBIN_RGB("graphics/ornament/pal/stoneim.pmdpal") };

static const axmain sAxMainTitlebg1;
const SiroArchive gAxTitlebg1 = {"SIRO", &sAxMainTitlebg1};

static const ax_pose sTitlebg1Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose2[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(5, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose3[] = {
	AX_POSE(6, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(7, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose4[] = {
	AX_POSE(8, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(9, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose5[] = {
	AX_POSE(10, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(11, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose6[] = {
	AX_POSE(12, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(13, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose7[] = {
	AX_POSE(14, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(15, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose8[] = {
	AX_POSE(16, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(17, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose9[] = {
	AX_POSE(18, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(19, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose10[] = {
	AX_POSE(20, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(21, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose11[] = {
	AX_POSE(22, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(23, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitlebg1Pose12[] = {
	AX_POSE(24, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(192, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(25, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(-1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(32, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(-1, OAM1(228, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(2, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(160, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(64, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(96, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(-1, OAM1(244, ST_OAM_SQUARE     , 1), OAM2(128, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(3, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(-1, OAM1(4, ST_OAM_SQUARE     , 2), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(48, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sTitlebg1Anims_1_1[] = {
	{ .frames = 6, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 6, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 7, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 8, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 9, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 10, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 11, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sTitlebg1Gfx1[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_1.4bpp");
static const ax_sprite sTitlebg1Sprites1[] = {
	{sTitlebg1Gfx1, ARRAY_COUNT(sTitlebg1Gfx1)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx2[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_2.4bpp");
static const ax_sprite sTitlebg1Sprites2[] = {
	{sTitlebg1Gfx2, ARRAY_COUNT(sTitlebg1Gfx2)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx3[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_3.4bpp");
static const ax_sprite sTitlebg1Sprites3[] = {
	{sTitlebg1Gfx3, ARRAY_COUNT(sTitlebg1Gfx3)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx4[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_4.4bpp");
static const u8 sTitlebg1Gfx4_2[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_4_2.4bpp");
static const ax_sprite sTitlebg1Sprites4[] = {
	{sTitlebg1Gfx4, ARRAY_COUNT(sTitlebg1Gfx4)},
	{NULL, 128},
	{sTitlebg1Gfx4_2, ARRAY_COUNT(sTitlebg1Gfx4_2)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx5[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_5.4bpp");
static const ax_sprite sTitlebg1Sprites5[] = {
	{sTitlebg1Gfx5, ARRAY_COUNT(sTitlebg1Gfx5)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx6[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_6.4bpp");
static const ax_sprite sTitlebg1Sprites6[] = {
	{sTitlebg1Gfx6, ARRAY_COUNT(sTitlebg1Gfx6)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx7[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_7.4bpp");
static const ax_sprite sTitlebg1Sprites7[] = {
	{sTitlebg1Gfx7, ARRAY_COUNT(sTitlebg1Gfx7)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx8[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_8.4bpp");
static const ax_sprite sTitlebg1Sprites8[] = {
	{sTitlebg1Gfx8, ARRAY_COUNT(sTitlebg1Gfx8)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx9[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_9.4bpp");
static const ax_sprite sTitlebg1Sprites9[] = {
	{sTitlebg1Gfx9, ARRAY_COUNT(sTitlebg1Gfx9)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx10[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_10.4bpp");
static const ax_sprite sTitlebg1Sprites10[] = {
	{sTitlebg1Gfx10, ARRAY_COUNT(sTitlebg1Gfx10)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx11[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_11.4bpp");
static const ax_sprite sTitlebg1Sprites11[] = {
	{sTitlebg1Gfx11, ARRAY_COUNT(sTitlebg1Gfx11)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx12[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_12.4bpp");
static const ax_sprite sTitlebg1Sprites12[] = {
	{sTitlebg1Gfx12, ARRAY_COUNT(sTitlebg1Gfx12)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx13[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_13.4bpp");
static const ax_sprite sTitlebg1Sprites13[] = {
	{sTitlebg1Gfx13, ARRAY_COUNT(sTitlebg1Gfx13)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx14[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_14.4bpp");
static const ax_sprite sTitlebg1Sprites14[] = {
	{sTitlebg1Gfx14, ARRAY_COUNT(sTitlebg1Gfx14)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx15[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_15.4bpp");
static const ax_sprite sTitlebg1Sprites15[] = {
	{sTitlebg1Gfx15, ARRAY_COUNT(sTitlebg1Gfx15)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx16[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_16.4bpp");
static const ax_sprite sTitlebg1Sprites16[] = {
	{sTitlebg1Gfx16, ARRAY_COUNT(sTitlebg1Gfx16)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx17[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_17.4bpp");
static const ax_sprite sTitlebg1Sprites17[] = {
	{sTitlebg1Gfx17, ARRAY_COUNT(sTitlebg1Gfx17)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx18[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_18.4bpp");
static const ax_sprite sTitlebg1Sprites18[] = {
	{sTitlebg1Gfx18, ARRAY_COUNT(sTitlebg1Gfx18)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx19[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_19.4bpp");
static const ax_sprite sTitlebg1Sprites19[] = {
	{sTitlebg1Gfx19, ARRAY_COUNT(sTitlebg1Gfx19)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx20[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_20.4bpp");
static const ax_sprite sTitlebg1Sprites20[] = {
	{sTitlebg1Gfx20, ARRAY_COUNT(sTitlebg1Gfx20)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx21[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_21.4bpp");
static const ax_sprite sTitlebg1Sprites21[] = {
	{sTitlebg1Gfx21, ARRAY_COUNT(sTitlebg1Gfx21)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx22[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_22.4bpp");
static const ax_sprite sTitlebg1Sprites22[] = {
	{sTitlebg1Gfx22, ARRAY_COUNT(sTitlebg1Gfx22)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx23[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_23.4bpp");
static const ax_sprite sTitlebg1Sprites23[] = {
	{sTitlebg1Gfx23, ARRAY_COUNT(sTitlebg1Gfx23)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx24[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_24.4bpp");
static const ax_sprite sTitlebg1Sprites24[] = {
	{sTitlebg1Gfx24, ARRAY_COUNT(sTitlebg1Gfx24)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx25[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_25.4bpp");
static const ax_sprite sTitlebg1Sprites25[] = {
	{sTitlebg1Gfx25, ARRAY_COUNT(sTitlebg1Gfx25)},
	{NULL, 0},
};
static const u8 sTitlebg1Gfx26[] = INCBIN_U8("graphics/ornament/Titlebg1/sprite_26.4bpp");
static const ax_sprite sTitlebg1Sprites26[] = {
	{sTitlebg1Gfx26, ARRAY_COUNT(sTitlebg1Gfx26)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesTitlebg1[] = {
	sTitlebg1Pose1,
	sTitlebg1Pose2,
	sTitlebg1Pose3,
	sTitlebg1Pose4,
	sTitlebg1Pose5,
	sTitlebg1Pose6,
	sTitlebg1Pose7,
	sTitlebg1Pose8,
	sTitlebg1Pose9,
	sTitlebg1Pose10,
	sTitlebg1Pose11,
	sTitlebg1Pose12,
};

static const ax_anim *const sTitlebg1AnimTable1[] = {
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
	sTitlebg1Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsTitlebg1[] = {
	sTitlebg1AnimTable1,
};

static const ax_sprite *const sAxSpritesTitlebg1[] = {
	sTitlebg1Sprites1,
	sTitlebg1Sprites2,
	sTitlebg1Sprites3,
	sTitlebg1Sprites4,
	sTitlebg1Sprites5,
	sTitlebg1Sprites6,
	sTitlebg1Sprites7,
	sTitlebg1Sprites8,
	sTitlebg1Sprites9,
	sTitlebg1Sprites10,
	sTitlebg1Sprites11,
	sTitlebg1Sprites12,
	sTitlebg1Sprites13,
	sTitlebg1Sprites14,
	sTitlebg1Sprites15,
	sTitlebg1Sprites16,
	sTitlebg1Sprites17,
	sTitlebg1Sprites18,
	sTitlebg1Sprites19,
	sTitlebg1Sprites20,
	sTitlebg1Sprites21,
	sTitlebg1Sprites22,
	sTitlebg1Sprites23,
	sTitlebg1Sprites24,
	sTitlebg1Sprites25,
	sTitlebg1Sprites26,
};

static const axmain sAxMainTitlebg1 = {
	.poses = sAxPosesTitlebg1,
	.animations = sAxAnimationsTitlebg1,
	.animCount = ARRAY_COUNT(sAxAnimationsTitlebg1),
	.spriteData = sAxSpritesTitlebg1,
	.positions = NULL,
};
const RGB gTitlebgPal[] = { INCBIN_RGB("graphics/ornament/pal/titlebg.pmdpal") };

static const axmain sAxMainTitleop1;
const SiroArchive gAxTitleop1 = {"SIRO", &sAxMainTitleop1};

static const ax_pose sTitleop1Pose1[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(1, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose2[] = {
	AX_POSE(2, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(3, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose3[] = {
	AX_POSE(4, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(5, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose4[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(7, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose5[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(9, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose6[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(11, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose7[] = {
	AX_POSE(12, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(13, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(14, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(24, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(24, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose8[] = {
	AX_POSE(15, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(228, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(16, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose9[] = {
	AX_POSE(17, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(18, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(19, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(32, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose10[] = {
	AX_POSE(20, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(220, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(21, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(22, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(28, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose11[] = {
	AX_POSE(23, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(212, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(24, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(25, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(20, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(26, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(27, OAM1(16, ST_OAM_H_RECTANGLE, 2), OAM2(236, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(50, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose12[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(1, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose13[] = {
	AX_POSE(2, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(3, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose14[] = {
	AX_POSE(4, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(5, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose15[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(7, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose16[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(9, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose17[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(11, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose18[] = {
	AX_POSE(12, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(13, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(14, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(224, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(24, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose19[] = {
	AX_POSE(15, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(16, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(220, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose20[] = {
	AX_POSE(17, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(18, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(19, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(216, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose21[] = {
	AX_POSE(20, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(21, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(228, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(22, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(212, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose22[] = {
	AX_POSE(23, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(12, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(24, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(25, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(204, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(26, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(27, OAM1(16, ST_OAM_H_RECTANGLE, 2), OAM2(244, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(50, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose23[] = {
	AX_POSE(28, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose24[] = {
	AX_POSE(29, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose25[] = {
	AX_POSE(30, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose26[] = {
	AX_POSE(31, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose27[] = {
	AX_POSE(28, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose28[] = {
	AX_POSE(29, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose29[] = {
	AX_POSE(30, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose30[] = {
	AX_POSE(31, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose31[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(1, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose32[] = {
	AX_POSE(2, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(3, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose33[] = {
	AX_POSE(4, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(5, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose34[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(7, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose35[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(9, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose36[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(11, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose37[] = {
	AX_POSE(12, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(232, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(13, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(8, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(14, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(24, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(24, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose38[] = {
	AX_POSE(15, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(228, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(16, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose39[] = {
	AX_POSE(17, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(18, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(16, 3, 13)),
	AX_POSE(19, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(32, ST_OAM_SIZE_1, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose40[] = {
	AX_POSE(20, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(220, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(21, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(22, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(28, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose41[] = {
	AX_POSE(23, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(212, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(24, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(244, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(25, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(20, ST_OAM_SIZE_2, FLIP(0, 0), 0, 1), OAM3(32, 3, 13)),
	AX_POSE(26, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(244, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(27, OAM1(16, ST_OAM_H_RECTANGLE, 2), OAM2(236, ST_OAM_SIZE_1, FLIP(0, 0), 0, 0), OAM3(50, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose42[] = {
	AX_POSE(0, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(1, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose43[] = {
	AX_POSE(2, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(3, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose44[] = {
	AX_POSE(4, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(5, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose45[] = {
	AX_POSE(6, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(7, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose46[] = {
	AX_POSE(8, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(9, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose47[] = {
	AX_POSE(10, OAM1(236, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(11, OAM1(236, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose48[] = {
	AX_POSE(12, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(248, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(13, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(232, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(14, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(224, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(24, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose49[] = {
	AX_POSE(15, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE(16, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(220, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose50[] = {
	AX_POSE(17, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(0, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(18, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(224, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(19, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(216, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose51[] = {
	AX_POSE(20, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(4, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(21, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(228, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(22, OAM1(240, ST_OAM_V_RECTANGLE, 1), OAM2(212, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose52[] = {
	AX_POSE(23, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(12, ST_OAM_SIZE_2, FLIP(1, 0), 0, 1), OAM3(0, 3, 13)),
	AX_POSE(24, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(236, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(16, 3, 13)),
	AX_POSE(25, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(204, ST_OAM_SIZE_2, FLIP(1, 0), 0, 0), OAM3(32, 3, 13)),
	AX_POSE(26, OAM1(232, ST_OAM_H_RECTANGLE, 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(48, 3, 13)),
	AX_POSE(27, OAM1(16, ST_OAM_H_RECTANGLE, 2), OAM2(244, ST_OAM_SIZE_1, FLIP(1, 0), 0, 0), OAM3(50, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose53[] = {
	AX_POSE(28, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose54[] = {
	AX_POSE(29, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose55[] = {
	AX_POSE(30, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose56[] = {
	AX_POSE(31, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(0, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose57[] = {
	AX_POSE(28, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose58[] = {
	AX_POSE(29, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose59[] = {
	AX_POSE(30, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_pose sTitleop1Pose60[] = {
	AX_POSE(31, OAM1(252, ST_OAM_SQUARE     , 1), OAM2(252, ST_OAM_SIZE_0, FLIP(1, 0), 0, 0), OAM3(0, 3, 5)),
	AX_POSE_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_1[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 11, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 12, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 13, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 14, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 15, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 16, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_2[] = {
	{ .frames = 9, .unkFlags = 0, .poseId = 11, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_3[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 17, .offset = {1, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_4[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 18, .offset = {1, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_5[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 19, .offset = {0, -4}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_6[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 20, .offset = {-1, -6}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 21, .offset = {-2, -9}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_1_8[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 26, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 27, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 28, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 29, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 28, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 27, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_1[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 30, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 31, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 32, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 33, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 34, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 35, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_2[] = {
	{ .frames = 9, .unkFlags = 0, .poseId = 30, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_3[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 36, .offset = {-1, -1}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_4[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 37, .offset = {0, -2}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_5[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 38, .offset = {1, -3}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_6[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 39, .offset = {2, -5}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_7[] = {
	{ .frames = 8, .unkFlags = 0, .poseId = 40, .offset = {3, -8}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop1Anims_2_8[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 52, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 53, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 54, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 55, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 54, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 53, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sTitleop1Gfx1[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_1.4bpp");
static const u8 sTitleop1Gfx1_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_1_2.4bpp");
static const u8 sTitleop1Gfx1_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_1_3.4bpp");
static const ax_sprite sTitleop1Sprites1[] = {
	{NULL, 64},
	{sTitleop1Gfx1, ARRAY_COUNT(sTitleop1Gfx1)},
	{NULL, 32},
	{sTitleop1Gfx1_2, ARRAY_COUNT(sTitleop1Gfx1_2)},
	{NULL, 32},
	{sTitleop1Gfx1_3, ARRAY_COUNT(sTitleop1Gfx1_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_2.4bpp");
static const ax_sprite sTitleop1Sprites2[] = {
	{NULL, 64},
	{sTitleop1Gfx2, ARRAY_COUNT(sTitleop1Gfx2)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_3.4bpp");
static const u8 sTitleop1Gfx3_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_3_2.4bpp");
static const ax_sprite sTitleop1Sprites3[] = {
	{NULL, 64},
	{sTitleop1Gfx3, ARRAY_COUNT(sTitleop1Gfx3)},
	{NULL, 32},
	{sTitleop1Gfx3_2, ARRAY_COUNT(sTitleop1Gfx3_2)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx4[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_4.4bpp");
static const ax_sprite sTitleop1Sprites4[] = {
	{NULL, 128},
	{sTitleop1Gfx4, ARRAY_COUNT(sTitleop1Gfx4)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx5[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_5.4bpp");
static const u8 sTitleop1Gfx5_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_5_2.4bpp");
static const u8 sTitleop1Gfx5_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_5_3.4bpp");
static const ax_sprite sTitleop1Sprites5[] = {
	{NULL, 64},
	{sTitleop1Gfx5, ARRAY_COUNT(sTitleop1Gfx5)},
	{NULL, 32},
	{sTitleop1Gfx5_2, ARRAY_COUNT(sTitleop1Gfx5_2)},
	{NULL, 32},
	{sTitleop1Gfx5_3, ARRAY_COUNT(sTitleop1Gfx5_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx6[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_6.4bpp");
static const u8 sTitleop1Gfx6_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_6_2.4bpp");
static const u8 sTitleop1Gfx6_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_6_3.4bpp");
static const ax_sprite sTitleop1Sprites6[] = {
	{NULL, 64},
	{sTitleop1Gfx6, ARRAY_COUNT(sTitleop1Gfx6)},
	{NULL, 32},
	{sTitleop1Gfx6_2, ARRAY_COUNT(sTitleop1Gfx6_2)},
	{NULL, 32},
	{sTitleop1Gfx6_3, ARRAY_COUNT(sTitleop1Gfx6_3)},
	{NULL, 32},
	{NULL, 0},
};
static const u8 sTitleop1Gfx7[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_7.4bpp");
static const u8 sTitleop1Gfx7_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_7_2.4bpp");
static const ax_sprite sTitleop1Sprites7[] = {
	{NULL, 64},
	{sTitleop1Gfx7, ARRAY_COUNT(sTitleop1Gfx7)},
	{NULL, 32},
	{sTitleop1Gfx7_2, ARRAY_COUNT(sTitleop1Gfx7_2)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx8[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_8.4bpp");
static const u8 sTitleop1Gfx8_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_8_2.4bpp");
static const u8 sTitleop1Gfx8_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_8_3.4bpp");
static const ax_sprite sTitleop1Sprites8[] = {
	{NULL, 64},
	{sTitleop1Gfx8, ARRAY_COUNT(sTitleop1Gfx8)},
	{NULL, 32},
	{sTitleop1Gfx8_2, ARRAY_COUNT(sTitleop1Gfx8_2)},
	{NULL, 32},
	{sTitleop1Gfx8_3, ARRAY_COUNT(sTitleop1Gfx8_3)},
	{NULL, 32},
	{NULL, 0},
};
static const u8 sTitleop1Gfx9[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_9.4bpp");
static const u8 sTitleop1Gfx9_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_9_2.4bpp");
static const u8 sTitleop1Gfx9_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_9_3.4bpp");
static const ax_sprite sTitleop1Sprites9[] = {
	{NULL, 64},
	{sTitleop1Gfx9, ARRAY_COUNT(sTitleop1Gfx9)},
	{NULL, 32},
	{sTitleop1Gfx9_2, ARRAY_COUNT(sTitleop1Gfx9_2)},
	{NULL, 32},
	{sTitleop1Gfx9_3, ARRAY_COUNT(sTitleop1Gfx9_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx10[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_10.4bpp");
static const ax_sprite sTitleop1Sprites10[] = {
	{NULL, 64},
	{sTitleop1Gfx10, ARRAY_COUNT(sTitleop1Gfx10)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx11[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_11.4bpp");
static const u8 sTitleop1Gfx11_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_11_2.4bpp");
static const u8 sTitleop1Gfx11_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_11_3.4bpp");
static const u8 sTitleop1Gfx11_4[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_11_4.4bpp");
static const ax_sprite sTitleop1Sprites11[] = {
	{sTitleop1Gfx11, ARRAY_COUNT(sTitleop1Gfx11)},
	{NULL, 64},
	{sTitleop1Gfx11_2, ARRAY_COUNT(sTitleop1Gfx11_2)},
	{NULL, 32},
	{sTitleop1Gfx11_3, ARRAY_COUNT(sTitleop1Gfx11_3)},
	{NULL, 32},
	{sTitleop1Gfx11_4, ARRAY_COUNT(sTitleop1Gfx11_4)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx12[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_12.4bpp");
static const ax_sprite sTitleop1Sprites12[] = {
	{sTitleop1Gfx12, ARRAY_COUNT(sTitleop1Gfx12)},
	{NULL, 96},
	{NULL, 0},
};
static const u8 sTitleop1Gfx13[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_13.4bpp");
static const u8 sTitleop1Gfx13_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_13_2.4bpp");
static const u8 sTitleop1Gfx13_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_13_3.4bpp");
static const ax_sprite sTitleop1Sprites13[] = {
	{NULL, 32},
	{sTitleop1Gfx13, ARRAY_COUNT(sTitleop1Gfx13)},
	{NULL, 32},
	{sTitleop1Gfx13_2, ARRAY_COUNT(sTitleop1Gfx13_2)},
	{NULL, 64},
	{sTitleop1Gfx13_3, ARRAY_COUNT(sTitleop1Gfx13_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx14[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_14.4bpp");
static const ax_sprite sTitleop1Sprites14[] = {
	{NULL, 64},
	{sTitleop1Gfx14, ARRAY_COUNT(sTitleop1Gfx14)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx15[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_15.4bpp");
static const ax_sprite sTitleop1Sprites15[] = {
	{NULL, 32},
	{sTitleop1Gfx15, ARRAY_COUNT(sTitleop1Gfx15)},
	{NULL, 32},
	{NULL, 0},
};
static const u8 sTitleop1Gfx16[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_16.4bpp");
static const u8 sTitleop1Gfx16_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_16_2.4bpp");
static const u8 sTitleop1Gfx16_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_16_3.4bpp");
static const ax_sprite sTitleop1Sprites16[] = {
	{sTitleop1Gfx16, ARRAY_COUNT(sTitleop1Gfx16)},
	{NULL, 32},
	{sTitleop1Gfx16_2, ARRAY_COUNT(sTitleop1Gfx16_2)},
	{NULL, 64},
	{sTitleop1Gfx16_3, ARRAY_COUNT(sTitleop1Gfx16_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx17[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_17.4bpp");
static const u8 sTitleop1Gfx17_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_17_2.4bpp");
static const ax_sprite sTitleop1Sprites17[] = {
	{sTitleop1Gfx17, ARRAY_COUNT(sTitleop1Gfx17)},
	{NULL, 96},
	{sTitleop1Gfx17_2, ARRAY_COUNT(sTitleop1Gfx17_2)},
	{NULL, 96},
	{NULL, 0},
};
static const u8 sTitleop1Gfx18[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_18.4bpp");
static const u8 sTitleop1Gfx18_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_18_2.4bpp");
static const u8 sTitleop1Gfx18_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_18_3.4bpp");
static const ax_sprite sTitleop1Sprites18[] = {
	{sTitleop1Gfx18, ARRAY_COUNT(sTitleop1Gfx18)},
	{NULL, 32},
	{sTitleop1Gfx18_2, ARRAY_COUNT(sTitleop1Gfx18_2)},
	{NULL, 64},
	{sTitleop1Gfx18_3, ARRAY_COUNT(sTitleop1Gfx18_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx19[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_19.4bpp");
static const u8 sTitleop1Gfx19_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_19_2.4bpp");
static const ax_sprite sTitleop1Sprites19[] = {
	{sTitleop1Gfx19, ARRAY_COUNT(sTitleop1Gfx19)},
	{NULL, 96},
	{sTitleop1Gfx19_2, ARRAY_COUNT(sTitleop1Gfx19_2)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx20[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_20.4bpp");
static const ax_sprite sTitleop1Sprites20[] = {
	{NULL, 32},
	{sTitleop1Gfx20, ARRAY_COUNT(sTitleop1Gfx20)},
	{NULL, 32},
	{NULL, 0},
};
static const u8 sTitleop1Gfx21[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_21.4bpp");
static const u8 sTitleop1Gfx21_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_21_2.4bpp");
static const u8 sTitleop1Gfx21_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_21_3.4bpp");
static const ax_sprite sTitleop1Sprites21[] = {
	{sTitleop1Gfx21, ARRAY_COUNT(sTitleop1Gfx21)},
	{NULL, 32},
	{sTitleop1Gfx21_2, ARRAY_COUNT(sTitleop1Gfx21_2)},
	{NULL, 64},
	{sTitleop1Gfx21_3, ARRAY_COUNT(sTitleop1Gfx21_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx22[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_22.4bpp");
static const u8 sTitleop1Gfx22_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_22_2.4bpp");
static const ax_sprite sTitleop1Sprites22[] = {
	{sTitleop1Gfx22, ARRAY_COUNT(sTitleop1Gfx22)},
	{NULL, 32},
	{sTitleop1Gfx22_2, ARRAY_COUNT(sTitleop1Gfx22_2)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx23[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_23.4bpp");
static const u8 sTitleop1Gfx23_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_23_2.4bpp");
static const ax_sprite sTitleop1Sprites23[] = {
	{sTitleop1Gfx23, ARRAY_COUNT(sTitleop1Gfx23)},
	{NULL, 32},
	{sTitleop1Gfx23_2, ARRAY_COUNT(sTitleop1Gfx23_2)},
	{NULL, 64},
	{NULL, 0},
};
static const u8 sTitleop1Gfx24[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_24.4bpp");
static const u8 sTitleop1Gfx24_2[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_24_2.4bpp");
static const u8 sTitleop1Gfx24_3[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_24_3.4bpp");
static const ax_sprite sTitleop1Sprites24[] = {
	{sTitleop1Gfx24, ARRAY_COUNT(sTitleop1Gfx24)},
	{NULL, 32},
	{sTitleop1Gfx24_2, ARRAY_COUNT(sTitleop1Gfx24_2)},
	{NULL, 64},
	{sTitleop1Gfx24_3, ARRAY_COUNT(sTitleop1Gfx24_3)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx25[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_25.4bpp");
static const ax_sprite sTitleop1Sprites25[] = {
	{sTitleop1Gfx25, ARRAY_COUNT(sTitleop1Gfx25)},
	{NULL, 32},
	{NULL, 0},
};
static const u8 sTitleop1Gfx26[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_26.4bpp");
static const ax_sprite sTitleop1Sprites26[] = {
	{sTitleop1Gfx26, ARRAY_COUNT(sTitleop1Gfx26)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sTitleop1Gfx27[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_27.4bpp");
static const ax_sprite sTitleop1Sprites27[] = {
	{sTitleop1Gfx27, ARRAY_COUNT(sTitleop1Gfx27)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx28[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_28.4bpp");
static const ax_sprite sTitleop1Sprites28[] = {
	{sTitleop1Gfx28, ARRAY_COUNT(sTitleop1Gfx28)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx29[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_29.4bpp");
static const ax_sprite sTitleop1Sprites29[] = {
	{sTitleop1Gfx29, ARRAY_COUNT(sTitleop1Gfx29)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx30[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_30.4bpp");
static const ax_sprite sTitleop1Sprites30[] = {
	{sTitleop1Gfx30, ARRAY_COUNT(sTitleop1Gfx30)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx31[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_31.4bpp");
static const ax_sprite sTitleop1Sprites31[] = {
	{sTitleop1Gfx31, ARRAY_COUNT(sTitleop1Gfx31)},
	{NULL, 0},
};
static const u8 sTitleop1Gfx32[] = INCBIN_U8("graphics/ornament/Titleop1/sprite_32.4bpp");
static const ax_sprite sTitleop1Sprites32[] = {
	{sTitleop1Gfx32, ARRAY_COUNT(sTitleop1Gfx32)},
	{NULL, 0},
};

static const ax_pose *const sAxPosesTitleop1[] = {
	sTitleop1Pose1,
	sTitleop1Pose2,
	sTitleop1Pose3,
	sTitleop1Pose4,
	sTitleop1Pose5,
	sTitleop1Pose6,
	sTitleop1Pose7,
	sTitleop1Pose8,
	sTitleop1Pose9,
	sTitleop1Pose10,
	sTitleop1Pose11,
	sTitleop1Pose12,
	sTitleop1Pose13,
	sTitleop1Pose14,
	sTitleop1Pose15,
	sTitleop1Pose16,
	sTitleop1Pose17,
	sTitleop1Pose18,
	sTitleop1Pose19,
	sTitleop1Pose20,
	sTitleop1Pose21,
	sTitleop1Pose22,
	sTitleop1Pose23,
	sTitleop1Pose24,
	sTitleop1Pose25,
	sTitleop1Pose26,
	sTitleop1Pose27,
	sTitleop1Pose28,
	sTitleop1Pose29,
	sTitleop1Pose30,
	sTitleop1Pose31,
	sTitleop1Pose32,
	sTitleop1Pose33,
	sTitleop1Pose34,
	sTitleop1Pose35,
	sTitleop1Pose36,
	sTitleop1Pose37,
	sTitleop1Pose38,
	sTitleop1Pose39,
	sTitleop1Pose40,
	sTitleop1Pose41,
	sTitleop1Pose42,
	sTitleop1Pose43,
	sTitleop1Pose44,
	sTitleop1Pose45,
	sTitleop1Pose46,
	sTitleop1Pose47,
	sTitleop1Pose48,
	sTitleop1Pose49,
	sTitleop1Pose50,
	sTitleop1Pose51,
	sTitleop1Pose52,
	sTitleop1Pose53,
	sTitleop1Pose54,
	sTitleop1Pose55,
	sTitleop1Pose56,
	sTitleop1Pose57,
	sTitleop1Pose58,
	sTitleop1Pose59,
	sTitleop1Pose60,
};

static const ax_anim *const sTitleop1AnimTable1[] = {
	sTitleop1Anims_1_1,
	sTitleop1Anims_1_2,
	sTitleop1Anims_1_3,
	sTitleop1Anims_1_4,
	sTitleop1Anims_1_5,
	sTitleop1Anims_1_6,
	sTitleop1Anims_1_7,
	sTitleop1Anims_1_8,
};

static const ax_anim *const sTitleop1AnimTable2[] = {
	sTitleop1Anims_2_1,
	sTitleop1Anims_2_2,
	sTitleop1Anims_2_3,
	sTitleop1Anims_2_4,
	sTitleop1Anims_2_5,
	sTitleop1Anims_2_6,
	sTitleop1Anims_2_7,
	sTitleop1Anims_2_8,
};

static const ax_anim *const *const sAxAnimationsTitleop1[] = {
	sTitleop1AnimTable1,
	sTitleop1AnimTable2,
};

static const ax_sprite *const sAxSpritesTitleop1[] = {
	sTitleop1Sprites1,
	sTitleop1Sprites2,
	sTitleop1Sprites3,
	sTitleop1Sprites4,
	sTitleop1Sprites5,
	sTitleop1Sprites6,
	sTitleop1Sprites7,
	sTitleop1Sprites8,
	sTitleop1Sprites9,
	sTitleop1Sprites10,
	sTitleop1Sprites11,
	sTitleop1Sprites12,
	sTitleop1Sprites13,
	sTitleop1Sprites14,
	sTitleop1Sprites15,
	sTitleop1Sprites16,
	sTitleop1Sprites17,
	sTitleop1Sprites18,
	sTitleop1Sprites19,
	sTitleop1Sprites20,
	sTitleop1Sprites21,
	sTitleop1Sprites22,
	sTitleop1Sprites23,
	sTitleop1Sprites24,
	sTitleop1Sprites25,
	sTitleop1Sprites26,
	sTitleop1Sprites27,
	sTitleop1Sprites28,
	sTitleop1Sprites29,
	sTitleop1Sprites30,
	sTitleop1Sprites31,
	sTitleop1Sprites32,
};

static const axmain sAxMainTitleop1 = {
	.poses = sAxPosesTitleop1,
	.animations = sAxAnimationsTitleop1,
	.animCount = ARRAY_COUNT(sAxAnimationsTitleop1),
	.spriteData = sAxSpritesTitleop1,
	.positions = NULL,
};
static const axmain sAxMainTitleop2;
const SiroArchive gAxTitleop2 = {"SIRO", &sAxMainTitleop2};

static const ax_pose sTitleop2Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_1[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_2[] = {
	{ .frames = 1, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {1, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {2, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {3, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 0, .offset = {4, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {3, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {2, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {1, 0}, .shadow = {0, 0} },
	{ .frames = 1, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {-1, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {-2, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {-3, 0}, .shadow = {0, 0} },
	{ .frames = 6, .unkFlags = 0, .poseId = 0, .offset = {-4, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {-3, 0}, .shadow = {0, 0} },
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {-2, 0}, .shadow = {0, 0} },
	{ .frames = 2, .unkFlags = 0, .poseId = 0, .offset = {-1, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_3[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_4[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_5[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_6[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_7[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const ax_anim sTitleop2Anims_1_8[] = {
	{ .frames = 3, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sTitleop2Gfx1[] = INCBIN_U8("graphics/ornament/Titleop2/sprite_1.4bpp");
static const u8 sTitleop2Gfx1_2[] = INCBIN_U8("graphics/ornament/Titleop2/sprite_1_2.4bpp");
static const ax_sprite sTitleop2Sprites1[] = {
	{sTitleop2Gfx1, ARRAY_COUNT(sTitleop2Gfx1)},
	{NULL, 32},
	{sTitleop2Gfx1_2, ARRAY_COUNT(sTitleop2Gfx1_2)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesTitleop2[] = {
	sTitleop2Pose1,
};

static const ax_anim *const sTitleop2AnimTable1[] = {
	sTitleop2Anims_1_1,
	sTitleop2Anims_1_2,
	sTitleop2Anims_1_3,
	sTitleop2Anims_1_4,
	sTitleop2Anims_1_5,
	sTitleop2Anims_1_6,
	sTitleop2Anims_1_7,
	sTitleop2Anims_1_8,
};

static const ax_anim *const *const sAxAnimationsTitleop2[] = {
	sTitleop2AnimTable1,
};

static const ax_sprite *const sAxSpritesTitleop2[] = {
	sTitleop2Sprites1,
};

static const axmain sAxMainTitleop2 = {
	.poses = sAxPosesTitleop2,
	.animations = sAxAnimationsTitleop2,
	.animCount = ARRAY_COUNT(sAxAnimationsTitleop2),
	.spriteData = sAxSpritesTitleop2,
	.positions = NULL,
};
const RGB gTitleopPal[] = { INCBIN_RGB("graphics/ornament/pal/titleop.pmdpal") };

