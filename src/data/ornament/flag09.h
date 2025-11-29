const RGB_Struct gFlag09Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag09.pmdpal") };

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
