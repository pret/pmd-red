const RGB_Struct gFlag01Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag01.pmdpal") };

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
