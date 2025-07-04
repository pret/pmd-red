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
