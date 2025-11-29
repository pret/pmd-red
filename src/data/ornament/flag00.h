const RGB_Struct gFlag00Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag00.pmdpal") };

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
