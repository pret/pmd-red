const RGB_Struct gFlag08Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag08.pmdpal") };

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
