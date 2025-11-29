const RGB_Struct gFlag14Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag14.pmdpal") };

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
