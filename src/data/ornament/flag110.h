const RGB_Struct gFlag110Pal[] = { INCBIN_RGB("graphics/ornament/pal/flag110.pmdpal") };

static const axmain sAxMainFlag110;
const SiroArchive gAxFlag110 = {"SIRO", &sAxMainFlag110};

static const ax_pose sFlag110Pose1[] = {
	AX_POSE(0, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose2[] = {
	AX_POSE(1, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose3[] = {
	AX_POSE(2, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose4[] = {
	AX_POSE(3, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose5[] = {
	AX_POSE(4, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_pose sFlag110Pose6[] = {
	AX_POSE(5, OAM1(240, ST_OAM_SQUARE     , 1), OAM2(240, ST_OAM_SIZE_2, FLIP(0, 0), 0, 0), OAM3(0, 3, 13)),
	AX_POSE_TERMINATOR
};
static const ax_anim sFlag110Anims_1_1[] = {
	{ .frames = 4, .unkFlags = 0, .poseId = 0, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 1, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 2, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 3, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 4, .offset = {0, 0}, .shadow = {0, 0} },
	{ .frames = 4, .unkFlags = 0, .poseId = 5, .offset = {0, 0}, .shadow = {0, 0} },
	AX_ANIM_TERMINATOR
};
static const u8 sFlag110Gfx1[] = INCBIN_U8("graphics/ornament/Flag110/sprite_1.4bpp");
static const ax_sprite sFlag110Sprites1[] = {
	{sFlag110Gfx1, ARRAY_COUNT(sFlag110Gfx1)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx2[] = INCBIN_U8("graphics/ornament/Flag110/sprite_2.4bpp");
static const ax_sprite sFlag110Sprites2[] = {
	{sFlag110Gfx2, ARRAY_COUNT(sFlag110Gfx2)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx3[] = INCBIN_U8("graphics/ornament/Flag110/sprite_3.4bpp");
static const ax_sprite sFlag110Sprites3[] = {
	{sFlag110Gfx3, ARRAY_COUNT(sFlag110Gfx3)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx4[] = INCBIN_U8("graphics/ornament/Flag110/sprite_4.4bpp");
static const ax_sprite sFlag110Sprites4[] = {
	{sFlag110Gfx4, ARRAY_COUNT(sFlag110Gfx4)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx5[] = INCBIN_U8("graphics/ornament/Flag110/sprite_5.4bpp");
static const ax_sprite sFlag110Sprites5[] = {
	{sFlag110Gfx5, ARRAY_COUNT(sFlag110Gfx5)},
	{NULL, 128},
	{NULL, 0},
};
static const u8 sFlag110Gfx6[] = INCBIN_U8("graphics/ornament/Flag110/sprite_6.4bpp");
static const ax_sprite sFlag110Sprites6[] = {
	{sFlag110Gfx6, ARRAY_COUNT(sFlag110Gfx6)},
	{NULL, 128},
	{NULL, 0},
};

static const ax_pose *const sAxPosesFlag110[] = {
	sFlag110Pose1,
	sFlag110Pose2,
	sFlag110Pose3,
	sFlag110Pose4,
	sFlag110Pose5,
	sFlag110Pose6,
};

static const ax_anim *const sFlag110AnimTable1[] = {
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
	sFlag110Anims_1_1,
};

static const ax_anim *const *const sAxAnimationsFlag110[] = {
	sFlag110AnimTable1,
};

static const ax_sprite *const sAxSpritesFlag110[] = {
	sFlag110Sprites1,
	sFlag110Sprites2,
	sFlag110Sprites3,
	sFlag110Sprites4,
	sFlag110Sprites5,
	sFlag110Sprites6,
};

static const axmain sAxMainFlag110 = {
	.poses = sAxPosesFlag110,
	.animations = sAxAnimationsFlag110,
	.animCount = ARRAY_COUNT(sAxAnimationsFlag110),
	.spriteData = sAxSpritesFlag110,
	.positions = NULL,
};
